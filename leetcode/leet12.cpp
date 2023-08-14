/* 12. Integer to Roman
 * ********************
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, 2 is written as II in Roman numeral, just two one's added together.
 * 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given an integer, convert it to a roman numeral.
 * Example 1:
 * Input: num = 3
 * Output: "III"
 * Explanation: 3 is represented as 3 ones.
 * Example 2:
 * Input: num = 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * Example 3:
 * Input: num = 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string f1(int n, char big, char little, char mid)
{
	int i;
	string s(5, '\0');
	if (n == 9) {
		s[0] = little; s[1] = big;
	} else if (n >= 5) {
		s[0] = mid;
		for (i = 0; i < n - 5; ++i) s[i + 1] = little;
	} else if (n == 4) {
		s[0] = little; s[1] = mid;
	} else {
		for (i = 0; i < n; ++i) s[i] = little;
	}
	return s;
}

string sol(int n)
{
	string res;
	for (int i = 0; i < n/1000; ++i) res += "M";
	res += f1((n%1000)/100, 'M', 'C', 'D');
	res += f1((n%100)/10, 'C', 'X', 'L');
	res += f1(n%10, 'X', 'I', 'V');
	return res;
}

int main()
{
	vector<int> v = {3, 58, 1994, 3999, 7, 19, 91, 191, 9996};
	for (auto vv : v) {
		cout << vv << " => " << sol(vv) << endl;
	}
	return 0;
}
