/* 1880. Check if Word Equals Summation of Two Words
 * *************************************************
 * The letter value of a letter is its position in the alphabet starting
 * from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).
 * The numerical value of some string of lowercase English letters s is the
 * concatenation of the letter values of each letter in s, which is then
 * converted into an integer.
 * For example, if s = "acb", we concatenate each letter's letter value,
 * resulting in "021". After converting it, we get 21.
 * You are given three strings firstWord, secondWord, and targetWord,
 * each consisting of lowercase English letters 'a' through 'j' inclusive.
 * Return true if the summation of the numerical values of firstWord and
 * secondWord equals the numerical value of targetWord, or false otherwise.
 * Example:
 * Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
 * Output: true
 * Explanation:
 * The numerical value of firstWord is "acb" -> "021" -> 21.
 * The numerical value of secondWord is "cba" -> "210" -> 210.
 * The numerical value of targetWord is "cdb" -> "231" -> 231.
 * We return true because 21 + 210 == 231.
 * */
#include <iostream>
#include <string>
using namespace std;

int convert(string str)
{
	int res = 0;
	for (auto&& c : str) {
		res = res*10 + c - 'a';
	}
	return res;
}

bool sol(string a, string b, string c)
{
	int ia = convert(a);
	int ib = convert(b);
	int ic = convert(c);
	cout << a << " + " << b << " ?= " << c << endl;
	cout << ia << " + " << ib << " ?= " << ic << endl;

	bool res = ic == ia + ib;
	cout << (res ? "+" : "-") << endl;
	if (!res) cout << a << " + " << b << " = " << ia + ib << endl;
	return res;
}

int main()
{
	sol("acb", "cba", "cdb");
	sol("aaa", "a", "aab");
	sol("aaa", "a", "aaaa");
	sol("cdefghij", "jihgfedc", "bcccccccb");
	return 0;
}
