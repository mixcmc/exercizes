/* 2sum.cpp
 *
 * Check if there are two numbers in the array that adds up to given number.
 * */
#include <iostream>
#include <vector>
#include <iterator>
using std::cout, std::endl, std::vector, std::prev;

bool solve(vector<int> &v, int val)
{
	if (v.empty()) {
		cout << "Vector empty\n";
		return false;
	}
	auto l = v.begin();
	auto r = prev(v.end());
	while (l != r) {
		auto sum = *l + *r;
		if (sum == val) {
			cout << *l << " + " << *r << " " << val << endl;
			return true;
		}
		if (sum > val && *l > *r) ++l;
		else --r;
	}
	cout << "Not found\n";
	return false;
}

int main()
{
	vector<int> v = {1,2,3,4,5,6};
	solve(v, 3);
	solve(v, 7);
	solve(v, 5);
	solve(v, 1);
	solve(v, 2);

	vector<int> vv;
	solve(vv, 3);

	vector<int> vvv = {1};
	solve(vvv,1);

	vector<int> v4 = {1,2,3};
	solve(v4, 4);
	solve(v4, 2);

	return 0;
}
