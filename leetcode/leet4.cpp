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
#include <algorithm>
#include <iterator>
using namespace std;

double sol(vector<int>& v1, vector<int>& v2)
{
	vector<int> v;
	double res = 0;
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));
	int n = v.size();
	if (n & 1) res = v[n/2];
	else res = (double)(v[n/2] + v[n/2 - 1])/2;
	return res;
}
/* Ideas:
 * 1. if medians are m1 and m2 => final median is somewhere between m1 and m2
 * 2. median is in the middle of combined array
 * 3. for array with bigger median get median idx, and check how many elements from smaller
 * array will be stored in combined array
 * */

int main()
{
	vector<int> v1 = {1,3}, v2 = {2};
	vector<int> v3 = {1,2}, v4 = {3,4};
	cout << sol(v1, v2) << endl;
	cout << sol(v3, v4) << endl;
	return 0;
}
