/* 11. Container With Most Water
 * *****************************
 * You are given an integer array height of length n.
 * There are n vertical lines drawn such that the two endpoints
 * of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container,
 * such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 * Example:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 * In this case, the max area of water the container can contain is 49.
 * 8     =              =
 * 7     =++++++++++++++=+++++=
 * 6     =  =           =     =
 * 5     =  =     =     =     =
 * 4     =  =     =  =  =     =
 * 3     =  =     =  =  =  =  =
 * 2     =  =  =  =  =  =  =  =
 * 1 =   =  =  =  =  =  =  =  =
 * =============================
 * */
#include <iostream>
#include <vector>
using namespace std;


int sol(vector<int>& v)
{
	int res = 0;
	vector<int> vol(v.size(), 0);
	/* O(n^2)*/
	for (int i = 0; i < v.size(); ++i) {
		int rmax = i, lmax = i;
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[j] >= v[i]) rmax = j;
		}
		for (int j = i - 1; j >= 0; --j) {
			if (v[j] >= v[i]) lmax = j;
		}
		vol[i] = v[i]*(rmax - lmax);
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << i << ": " << v[i] << " => " << vol[i] << endl;
		res = vol[i] > res ? vol[i] : res;
	}
	return res;
}


int main()
{
	vector<int> v0 = {1,8,6,2,5,4,8,3,7};
	vector<int> v1 = {1,1};
	vector<int> v2 = {1,2,3,2,1};
	vector<int> v3 = {1,2,3,4,5,6,7,8};
	vector<int> v4 = {8,7,6,5,4,3,2,1};
	cout << sol(v0) << endl;
	cout << sol(v1) << endl;
	cout << sol(v2) << endl;
	cout << sol(v3) << endl;
	cout << sol(v4) << endl;
	return 0;
}
