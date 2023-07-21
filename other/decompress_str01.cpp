/* decompress_str01.cpp
 * Decompress given compressed string.
 * 4a => aaaa
 * 3(ab) => ababab
 * 2(3b2(cd)) => bbbcdcdbbbcdcd
 * */
#include <iostream>
#include <string>
#include <unistd.h>

using std::cout, std::endl, std::string;

bool is_digit(char c) {
	return c >= '0' && c <= '9';
}
int get_digit(const string& s, size_t& idx)
{
	int digit = 0;
	while(idx <= s.size() && is_digit(s[idx])) {
		digit *=10;
		digit += s[idx++] - '0';
	}
	return digit;
}

string decompress_one_level(const string& s, size_t& idx, bool& last)
{
	int l = 0, r = 0;
	string res;
	while (idx <= s.size()) {
		//cout << "checking " << s[idx];
		if (s[idx] == '(') {
			l++;
			last = false;
		//	cout << " f";
			if (l == 1) {
				idx++;
		//		cout << endl;
				continue;
			}
		}
		else if (s[idx] == ')') {
			r++;
			last = false;
		//	cout << " f";
			if (l == r) {
				idx++;
		//		cout << endl;
				break;
			}
		}
		if (is_digit(s[idx])) {
			last = false;
		//	cout << " f";
		}
		res+=s[idx];
		//cout << " +\n";
		idx++;
		if (l == 0) break;
	}
	//cout << res << endl;
	return res;
}

void decompress(const string& s)
{
	string ss, sc = s;
	size_t iter = 1;
	bool last;
	cout << s << endl;
	do {
		last = true;
		cout << "Iter" << iter++ << endl;
		size_t idx = 0;
		while (idx <= sc.size()) {
			if (is_digit(sc[idx])) {
				int digit = get_digit(sc, idx);
				string sss = decompress_one_level(sc, idx, last);
				while(digit-- > 0) ss += sss;
			}
			ss+=sc[idx++];
		}
		sc = ss;
		ss = "";
		cout << sc << endl;
	} while (!last);
	cout << "final: " << sc << endl;
}

int main()
{
	string s("ab2(c3(dir))f4aa12aba");
	string ss("a1b2c3(d4(e3(ff)))zz");
	decompress(s);
	decompress(ss);
	return 0;
}
