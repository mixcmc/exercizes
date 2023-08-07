/* 1877. Minimize Maximum Pair Sum in Array
 * ****************************************
 * The pair sum of a pair (a,b) is equal to a + b.
 * The maximum pair sum is the largest pair sum in a list of pairs.
 * For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum
 * would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
 * Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
 *  - Each element of nums is in exactly one pair, and
 *  - The maximum pair sum is minimized.
 * Return the minimized maximum pair sum after optimally pairing up the elements.
 * Example:
 * Input: nums = [3,5,2,3]
 * Output: 7
 * Explanation: The elements can be paired up into pairs (3,3) and (5,2).
 * The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int naive(vector<int>& v)
{
	sort(v.begin(), v.end());
	int min_max_pair = INT_MAX;
	while(next_permutation(v.begin(), v.end())) {
		int max_pair = INT_MIN;
		for(int i = 0; i < v.size(); i+=2) {
			int pair = v[i] + v[i+1];
			max_pair = (pair > max_pair ? pair : max_pair);
		}
		min_max_pair = (min_max_pair > max_pair ? max_pair : min_max_pair);
	}
	return min_max_pair;
}

int main()
{
	vector<int> v0 = {3,5,2,3};
	vector<int> v1 = {3,5,4,2,4,6};
	/* 3+3 and 5+2 => 7 */
	cout << naive(v0) << endl;
	/* 3+5, 4+4, 2+6 => 8 */
	cout << naive(v1) << endl;
	return 0;
}
