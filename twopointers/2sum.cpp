/* 2sum.cpp
 *
 * Check if there are two numbers in the array that adds up to given number.
 * */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout, std::endl, std::vector, std::prev, std::sort, std::copy;
using std::ostream_iterator;

bool solve(vector<int> &v, int val)
{
	if (v.empty()) {
		cout << "Vector is empty\n";
		return false;
	}
	auto l = v.begin();
	auto r = prev(v.end());
	cout << "search sum = " << val << endl;
	while (l != r) {
		auto sum = *l + *r;
		if (sum == val) {
			cout << *l << " + " << *r << " = " << val << endl;
			return true;
		}
		if (sum > val && *l > *r || sum < val && *l < *r) ++l;
		else --r;
	}
	cout << "Not found\n";
	return false;
}

void print_vector(vector<int>& v)
{
	cout << "{";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << "}\n";
}

int main()
{
	vector<int> v = {1,2,3,4,5,6};
	print_vector(v);
	solve(v, 3);
	solve(v, 7);
	solve(v, 5);
	solve(v, 1);
	solve(v, 2);

	vector<int> vv;
	print_vector(vv);
	solve(vv, 3);

	vector<int> vvv = {1};
	print_vector(vvv);
	solve(vvv,1);

	vector<int> v4 = {1,2,3};
	print_vector(v4);
	solve(v4, 4);
	solve(v4, 2);

	return 0;
}
