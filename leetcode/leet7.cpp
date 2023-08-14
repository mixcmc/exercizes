/* 7. Reverse Integer
 * ******************
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * Example 1:
 * Input: x = 123
 * Output: 321
 * Example 2:
 * Input: x = -123
 * Output: -321
 * Example 3:
 * Input: x = 120
 * Output: 21
 * */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sol(int n)
{
	int res = 0;
	while(n != 0) {
		if (res > INT_MAX / 10 || res < INT_MIN / 10) {
			cout << "(Over/underflow)";
			return 0;
		}
		res = res*10 + n%10;
		n /= 10;
	}
	return res;
}

int main()
{
	vector<int> v = {
		123, -123, 120, INT_MAX, INT_MIN, 0,
		222222222, -222222222,
        2111111112,-2111111112,
        2122222212,-2122222212,
	};
	for (auto n : v) {
		cout << n << " => " << sol(n) << endl;
	}
	return 0;
}
