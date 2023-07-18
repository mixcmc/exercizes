/* find_substr01.cpp
 * Given string contains only 0's and 1's.
 * Rightmost symbol is 0, leftmost is 1.
 * Find position of any '01' substring
 * */
#include <iostream>
#include <string>
#include <iterator>

using std::cout, std::endl, std::prev;
using std::string;

size_t solve(const string& s)
{
	size_t l = 0, r = s.size();
	while (l <= r) {
		auto mid = (l+r)/2;
		if (s[mid] == '0') {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return (l+r)/2;
}

void check_string(const string& s)
{
	string ss(s.size(), '.');
	size_t i = solve(s);
	cout << s << endl;
	if (i >= 0 || i <= s.size())
		ss[i] = '^';
	cout << ss << endl;
}

string gen_string(size_t len)
{
	string s(len, '0');
	s[s.size() - 1] = '1';
	for (int i = 1; i < s.size() - 1; ++i) {
		if (rand() & 1) s[i] = '1';
	}
	return s;
}

int main()
{
	string s1 = "01";
	string s2 = "011";
	string s3 = "0001001";
	string s4 = "010001";
	string s5 = "011111";
	string s6 = "01010101";
	string s7 = "00100001101";

	check_string(s1);
	check_string(s2);
	check_string(s3);
	check_string(s4);
	check_string(s5);
	check_string(s6);
	check_string(s7);

	srand(time(NULL));
	for(int i = 0; i < 15; ++i) {
		size_t len = 2 + (rand() % 10);
		check_string(gen_string(len));
	}

	return 0;
}
