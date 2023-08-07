/* 1835. Find XOR Sum of All Pairs Bitwise AND
 *********************************************
 * The XOR sum of a list is the bitwise XOR of all its elements.
 * If the list only contains one element, then its XOR sum will be equal to this element.
 * For example, the XOR sum of [1,2,3,4] is equal to 1 XOR 2 XOR 3 XOR 4 = 4,
 * and the XOR sum of [3] is equal to 3.
 * You are given two 0-indexed arrays arr1 and arr2 that consist only of non-negative integers.
 * Consider the list containing the result of arr1[i] AND arr2[j] (bitwise AND) for every (i, j)
 * pair where 0 <= i < arr1.length and 0 <= j < arr2.length.
 * Return the XOR sum of the aforementioned list.
 * Example:
 * Input: arr1 = [1,2,3], arr2 = [6,5]
 * Output: 0
 * Explanation: The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
 * The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.
 * */
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int naive(int *a, int *b, int asize, int bsize)
{
	int *ab = (int*)malloc(sizeof(*a)*asize*bsize);
	int i, j, res = 0;
	for (i=0; i<asize; ++i) {
		for (j=0; j<bsize; ++j) {
			ab[i*bsize + j] = a[i] & b[j];
		}
	}
	for (i=0; i<asize*bsize; ++i) res ^= ab[i];
	free(ab);
	return res;
}

/* [a,b,...], [c,d,...]:
 * (a & c) ^ (b & c)^... == (a^b^...) & c
 * and same for (axor & c) ^ (axor & d ) ^...
 * */
int sol(int *a, int *b, int asize, int bsize)
{
	int axor = a[0], bxor = b[0], i;
	for(i = 1; i < asize; ++i) axor ^= a[i];
	for(i = 1; i < bsize; ++i) bxor ^= b[i];
	return axor & bxor;
}

int sol1(const vector<int>& a, const vector<int>& b)
{
	int axor = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
	int bxor = accumulate(b.begin(), b.end(), 0, bit_xor<int>());
	return axor & bxor;
}

int main()
{
	int a[] = {3, 5, 7, 137, 7, 127, 166666, 72, 15, 0, 1};
	int b[] = {2, 1, 0, 0xf, 0xfff, 0xaffa, 0xf000, 0x80};
	int asz = sizeof(a)/sizeof(*a);
	int bsz = sizeof(b)/sizeof(*b);
	vector<int> av(a, a + asz), bv(b, b + bsz);

	printf("%d, %d, %d\n", naive(a,b,asz,bsz), sol(a,b,asz,bsz), sol1(av,bv));
	return 0;
}
