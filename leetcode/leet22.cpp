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
#include <unordered_set>
using namespace std;

/* -------------------------------------- */
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

/* bad solution  */
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
/* -------------------------------------- */
/* 1. total n left and n right parentheses
 * 2. on each step can open left or close right if have open left
 * */

void generator(vector<string>& v, int l, int r, string s, int& call_cnt)
{
	call_cnt++;
	if (l == 0 && r == 0) {
		v.push_back(s);
		return;
	}

	if (l > 0) generator(v, l - 1, r, s + '(', call_cnt);
	/* if no unbalanced '(' => no ')' */
	if (r > 0 && r > l) generator(v, l, r - 1, s + ')', call_cnt);
}

vector<string> sol1(int n)
{
	vector<string> res;
	string s;
	int call_cnt = 0;
	generator(res, n, n, s, call_cnt);
	cout << "call_cnt = " << call_cnt << endl;
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
void print_diff(const vector<string>& v1, const vector<string>& v2)
{
	unordered_set<string> s1, s2;
	for (auto s : v1) s1.insert(s);
	for (auto s : v2) s2.insert(s);

	/* bigger */
	auto s3 = (s1.size() > s2.size() ? s1 : s2);
	/* smaller  */
	auto s4 = (s1.size() < s2.size() ? s1 : s2);

	int cnt = 1;
	for (auto s : s3) {
		if (s4.count(s) == 0) {
			cout << "missing" << cnt++ << ": " << s << endl;
		}
	}
	cout << "Total " << cnt - 1 << " missing strings\n";
	cout << "----------------\n";
}

void print_doubles(const vector<string>& v)
{
	unordered_set<string> ss;
	int cnt = 0;
	for (auto s : v) {
		if (ss.count(s) > 0) {
			cout << "dup: " << s << endl;
			cnt++;
		}
		ss.insert(s);
	}
	cout << "Total " << cnt << " duplicates\n";
	cout << "----------------\n";
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		cout << "n = " << i << endl;
		//auto r0 = sol(i);
		auto r1 = sol1(i);
		//print(r0);
		//print_doubles(r0);
		//print(r1);
		//print_doubles(r1);
		//print_diff(r0, r1);
		cout << "Total " << r1.size() << " strings\n";
		cout << "----------------\n";
	}
	return 0;
}
