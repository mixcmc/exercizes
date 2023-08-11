/* 2. Add Two Numbers
 * ******************
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * */
#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0) {}
	ListNode(int val_) : val(val_) {}
	ListNode(int val_, ListNode *next_) : val(val_), next(next_) {}
};

ListNode* construct(int n)
{
	ListNode *l = new ListNode(), *l1 = l;
	while (n) {
		l->val = n % 10;
		n /= 10;
		if (!n) break;
		l->next = new ListNode();
		l = l->next;
	}
	return l1;
}

void append(ListNode *a, ListNode *b, int *carry)
{
	while (a && a->next) a = a->next;
	while (b) {
		int val = (b->val + *carry) % 10;
		*carry = (b->val + *carry) / 10;
		a->next = new ListNode(val);
		b = b->next;
		a = a->next;
	}
}

void print(ListNode *l)
{
	while (l) {
		cout << l->val << "->";
		l = l->next;
	}
	cout << "null\n";
}

ListNode* sol(ListNode *a, ListNode *b)
{
	ListNode *c = new ListNode(), *res = c;
	int carry = 0;
	while (a && b) {
		int val = (carry + a->val + b->val) % 10;
		carry = (carry + a->val + b->val) / 10;
		c->val = val;
		a = a->next;
		b = b->next;
		if (!a || !b) break;
		c->next = new ListNode();
		c = c->next;
	}
	append(c, a, &carry);
	append(c, b, &carry);
	if (carry != 0) {
		c->next = new ListNode(1);
	}
	return res;
}

int main()
{
	ListNode *l0 =  construct(123);
	ListNode *l1 = construct(0);
	ListNode *l2 = construct(INT_MAX);
	print(l0);
	print(l1);
	print(l2);
	cout << "-------\n";
	ListNode *l3 = sol(l0,l2);
	print(l3);
	cout << "-------\n";
	ListNode *l4 = construct(99989);
	print(l0);
	print(l4);
	ListNode *l5 = sol(l0, l4);
	print(l5);
	return 0;
}
