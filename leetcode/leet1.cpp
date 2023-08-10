/* 1. Two Sum
 * **********
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> sol(vector<int>& v, int targ)
{
	unordered_map<int,int> m;
	/* O(N) on average */
	for (int i = 0; i < v.size(); ++i)
		m[v[i]] = i;

	/* O(N) on average */
	for (int i = 0; i < v.size(); ++i) {
		int c = targ - v[i];
		if (m.count(c) && m[c] != i)
			return {i, m[c]};
	}
	return {};
}

vector<int> sol1(vector<int>& v, int targ)
{
	unordered_map<int,int> m;
	/* O(N) on average */
	for (int i = 0; i < v.size(); ++i) {
		int c = targ - v[i];
		if (m.count(c))
			return {m[c], i};
		m[v[i]] = i;
	}
	return {};
}

void print(vector<int> v)
{
	if (v.size() < 2) {
		cout << "{}\n";
		return;
	}
	cout << "{" << v[0] << ", " << v[1] << "}\n";
}

int main()
{
	vector<int> v0 = {2,7,11,15};
	vector<int> v1 = {3,2,4};
	vector<int> v2 = {3,3};
	print(sol(v0,9));print(sol1(v0,9));
	print(sol(v1,6));print(sol1(v1,6));
	print(sol(v2,6));print(sol1(v2,6));
	return 0;
}
