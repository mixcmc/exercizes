/* 15. 3Sum
 * ********
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * Example:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

void print_v(const vector<int>& v)
{
		cout << "[";
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
		cout << "]\n";
}

void print_vv(const vector<vector<int>>& vv)
{
	if (vv.empty()) cout << "{}\n";
	for(auto& v : vv) print_v(v);
}

vector<vector<int>> sol(vector<int>& v)
{
	vector<vector<int>> res;
	if (v.size() < 3) return res;
	/* O(nlogn) */
	sort(v.begin(), v.end());
	if (v[0] > 0) return res;

	/* O(n) * O(n) = O(n^2) */
	for (int i = 0; i < v.size(); ++i) {
		/* No solution in upper part if positive element */
		if (v[i] > 0) {
			break;
		}
		/* ignore dups */
		if (i > 0 && v[i] == v[i-1]) {
			continue;
		}
		int l = i + 1, r = v.size() - 1, s;
		/* search in upper part, lower part already processed, O(n) */
		while (l < r) {
			s = v[i] + v[l] + v[r];
			if (s > 0) {
				--r;
			} else if (s < 0) {
				++l;
			} else {
				res.push_back({v[i], v[l], v[r]});
				/* ignore dups */
				int prev_l = l, prev_r = r;
				while (l < r && v[l] == v[prev_l]) ++l;
				while (l < r && v[r] == v[prev_r]) --r;
			}
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> v = {
		{-1,0,1,2,-1,-4},
		{0,1,1},
		{0,0,0},
		{1,2,3,4,-1,-2,-3,-4},
		{1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,-2,-2,-2,-2,-2,2,2,2,2,2,0,-1,-1,-1,3,4,5,6,7},
	};
	for(auto& vv : v) {
		print_v(vv);
		cout << "=>\n";
		print_vv(sol(vv));
		cout << "---------\n";
	}
	return 0;
}
