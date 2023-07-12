/* calc_fun01.cpp
 * Find argument that corresponds to given func value using binary search
 *
 * Have no idea for what purpose I used rvalue references and std::move
 * */

#include <iostream>
#include <cmath>

using std::cout, std::endl, std::log2;

template <typename T, typename P = T>
requires std::is_floating_point_v<T> &&
		 std::is_floating_point_v<P>
T func(P&& arg)
{
	return arg*log2(arg);
}

template <typename T, typename P = T>
P solve(T (*func)(P&&), P&& l, P&& r, T&& x)
{
	P l_ = l, r_ = r;
	for(int i=0; i<100; ++i) {
		P mid = (l_ + r_)/2;
		T cur_res = func(std::move(mid));
		if (cur_res < x) {
			l_ = mid;
		} else {
			r_ = mid;
		}
	}
	return l_;
}

int main()
{
	double ans = solve(func<double>, 0.0, 10.0, 1.3);
	cout << "func(x) = 1.3 => x = " << ans << endl;
	cout << "func(" << ans << ") = " << func<double>(std::move(ans)) << endl;
	return 0;
}
