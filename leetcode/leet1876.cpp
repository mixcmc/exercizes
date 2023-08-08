/* 1876. Substrings of Size Three with Distinct Characters
 *********************************************************
 * A string is good if there are no repeated characters.
 * Given a string s, return the number of good substrings of length three in s.
 * Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
 * A substring is a contiguous sequence of characters in a string.
 * Example:
 * Input: s = "xyzzaz"
 * Output: 1
 * Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
 * The only good substring of length 3 is "xyz".
 * */
#include <iostream>
#include <string>
using namespace std;

int sol(const string& s)
{
	int ret = 0;
	cout << endl;
	for (int i = 0; i < s.length() - 2; ++i) {
		char a = s[i], b = s[i+1], c = s[i+2];
		if (a != b && a != c && b != c) {
			ret++;
			cout << a << b << c << " is good\n";
		} else {
			cout << a << b << c << " is bad\n";
		}
	}
	return ret;
}

int main()
{
	string s0 = "xyzzaz";
	string s1 = "aababcabc";
	/* 1 */
	cout << s0 << " => " << sol(s0) << endl;
	/* 4 */
	cout << s1 << " => " << sol(s1) << endl;
	return 0;
}
