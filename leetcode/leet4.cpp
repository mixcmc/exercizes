/* 4. Median of Two Sorted Arrays
 * ******************************
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * */
#include <iostream>
#include <vector>
using namespace std;

int sol(vector<int>& v1, vector<int>& v2)
{
	int res = 0;
	return res;
}

int main()
{
	vector<int> v1 = {1,3}, v2 = {2};
	cout << sol(v1, v2) << endl;
	return 0;
}
