#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <climits>
#include <unistd.h>

using std::cout, std::endl, std::vector, std::pair, std::set;

/*                           0123456789 */
const char *shades_levels = " .:-=+*#%@";
const char *full_shades_levels = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

int get_shades_level(char c) {
	int res = 9;
	while (res >=0 && c != shades_levels[res--]);
	return res + 1;
}

class Figure
{
	set<pair<int,int>> points;
	public:
		void add_point(int x, int y) {
			points.insert({x,y});
		}
		void move(int x, int y) {
			set<pair<int,int>> points_;
			for (auto& p : points) {
				points_.insert({p.first + x, p.second + y});
			}
			points.swap(points_);
		}
		void add_cross(int x, int y, int lenx, int leny)
		{
			for (int xx = x - lenx; xx <= x + lenx; ++xx) add_point(xx,y);
			for (int yy = y - leny; yy <= y + leny; ++yy) add_point(x,yy);
		}
		void add_line(int x0, int y0, int x1, int y1) {
			/* Bresenham's line algorithm */
			int dx = abs(x1 - x0);
			int dy = abs(y1 - y0);
			int err = 0;
			int derr = dy + 1;
			int y = y0, diry = y1 - y0;
			if (diry < 0) diry = -1;
			if (diry > 0) diry =  1;
			for (int x = x0; x <= x1; ++x) {
				add_point(x, y);
				err = err + derr;
				if (err > dx + 1) {
					y = y + diry;
					err = err - (dx + 1);
				}
			}

		}
		void add_circle(int xc, int yc, int r, int filled)
		{
			int x = 0, y = r;
			int d = 1 - 2*r;
			int err = 0;
			while (y >= x) {
				add_point(xc + x, yc + y);
				add_point(xc + x, yc - y);
				add_point(xc - x, yc + y);
				add_point(xc - x, yc - y);

				add_point(xc + y, yc + x);
				add_point(xc + y, yc - x);
				add_point(xc - y, yc + x);
				add_point(xc - y, yc - x);

				if (filled) {
					for (int yy = yc - y + 1; yy < yc + y; ++yy) {
						add_point(xc + x, yy);
						add_point(xc - x, yy);
					}
					for (int xx = xc - y + 1; xx < xc + y; ++xx) {
						add_point(xx, yc - x);
						add_point(xx, yc + x);
					}
				}

				err = 2*(d + y) - 1;
				if (d < 0 && err <= 0) {
					d += 2 * ++x + 1;
					continue;
				}
				if (d > 0 && err > 0) {
					d -= 2 * --y + 1;
					continue;
				}
				d += 2 * (++x - --y);
			}
		}
		const set<pair<int,int>>& get_coords(void) const
		{
			return points;
		}
};

class Field
{
	vector<char> field;
	vector<char> empty_field;
	vector<pair<Figure,char>> figures;
	size_t xsize;
	size_t ysize;

	public:
		Field(size_t xsize_, size_t ysize_, char c = '.')
			: xsize(xsize_), ysize(ysize_), field(xsize_*ysize_, c),
			  empty_field(xsize_*ysize_, c)
		{}
		void set_pixel(size_t x, size_t y, char c)
		{
			if (x >=0 && x < xsize && y >= 0 && y < ysize) {
				size_t idx = x + y*xsize;
				field[idx] = c;
			}
		}

		void add_figure(const Figure& f, char c)
		{
			figures.push_back({f,c});
		}

		void draw_figure(const Figure& f, char c)
		{
			for(const auto& p : f.get_coords()) {
				set_pixel(p.first, p.second, c);
			}
		}

		void set_fade(int min_level)
		{
			vector<char> f(field.size(), ' ');
			for (int x = 1; x < xsize - 1; ++x) {
				for (int y = 1; y < ysize - 1; ++y) {
					int idx0 = x + y*xsize;
					int idx1 = x + 1 + y*xsize;
					int idx2 = x - 1 + y*xsize;
					int idx3 = x + (y + 1)*xsize;
					int idx4 = x + (y - 1)*xsize;
					int l0 = get_shades_level(field[idx0]);
					int l1 = get_shades_level(field[idx1]);
					l1 += get_shades_level(field[idx2]);
					l1 += get_shades_level(field[idx3]);
					l1 += get_shades_level(field[idx4]);
					//l1 /= 4;
					l0 = (3*l0 + l1)/7;
					if (l0 <= min_level) l0 = min_level;
					f[idx0] = shades_levels[l0];
				}
			}
			field.swap(f);
		}

		void update(void) {
			field = empty_field;
			for (auto& f : figures) {
				draw_figure(f.first, f.second);
			}
		}

		void print(void)
		{
			for (int y = ysize - 1; y >= 0; --y) {
				for (int x = 0; x < xsize; ++x) {
					int idx = x + y*xsize;
					cout << field[idx];
				}
				cout << endl;
			}
			cout << endl;
		}

		void move_fig_by_id(int id, int x, int y)
		{
			if (id >=0 && id < figures.size()) {
				figures[id].first.move(x,y);
			}
		}
};

void clear_screen(void)
{
	system("tput clear");
}

int main()
{
	Field f(100,20);
	Figure fig, fig1;

/*	f.print();

	f.set_pixel(0,19,'#');
	f.set_pixel(9,0,'$');
	f.print();

	fig.add_line(0,0,20,20);
	f.add_figure(fig, '@');
	f.print();

	fig.add_line(20,20, 40, 0);
	f.add_figure(fig, '&');
	f.print();

	fig.add_line(0,19, 99, 0);
	f.add_figure(fig, '&');
	f.print();
*/
/*	fig.add_circle(20, 10, 7, 0);
	fig.move(2,-1);
	fig.add_circle(50, 10, 7, 1);
	f.add_figure(fig, shades_levels[9]);
	f.print();
*/

	fig.add_cross(20, 10, 5, 4);
	f.add_figure(fig, shades_levels[9]);
	f.update();
	f.print();

	cout << shades_levels << endl;
	f.set_fade(0);
	f.print();

	fig1.add_circle(60, 8, 5, 1);
	f.add_figure(fig1, shades_levels[9]);

	clear_screen();
	usleep(1000);

	int dir = 1;
	for (int i = 0; i < 20; ++i) {
		clear_screen();
		f.move_fig_by_id(0, dir, 0);
		f.move_fig_by_id(1, -dir, 0);
		f.update();
		f.set_fade(0);
		f.print();
		usleep(50000);

		if (i%50 == 49) {
			if (dir == 1) dir = -1;
			else dir = 1;
		}
	}

	return 0;
}
