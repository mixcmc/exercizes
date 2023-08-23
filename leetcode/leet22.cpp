/* 22. Generate Parentheses
 * ************************
 * Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 * Example:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool has_nested(const string& s)
{
	int p = 0;
	for(int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') p++;
		if (s[i] == ')') p--;
		if (p > 1) return true;
	}
	return false;
}

vector<string> sol(int n)
{
	vector<string> res;
	string s1, s2, s3;

	if (n == 0) {
		return res;
	}
	if (n == 1) {
		res.push_back("()");
		return res;
	}
	/* ~O(n*3^(n-1)):
	 * 3^(n-2) + 3^(n-3) + ... + 2 + 1 ~= (3^(n-1) - 1) / 2
	 * + O(n) for has_nested on each step */
	vector<string> r = sol(n-1);
	for (auto s : r) {
		res.push_back("(" + s + ")");
		res.push_back("()" + s);
		if (has_nested(s)) {
			res.push_back(s + "()");
		}
	}
	return res;
}

void print(const vector<string>& v)
{
	for(auto s : v) {
		cout << s << endl;
	}
	cout << "Total: " << v.size() << " strings\n";
	cout << "--------------\n";
}

int main()
{
	for (int i = 0; i < 8; ++i) {
		cout << "n = " << i << endl;
		print(sol(i));
	}
	return 0;
}
