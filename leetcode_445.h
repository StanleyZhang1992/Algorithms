#pragma once
/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stk1;
    stack<int> stk2;
    stack<int> resStk;
    while (l1) {
        stk1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        stk2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    while (!stk1.empty() && !stk2.empty()) {
        int cur1 = stk1.top();
        int cur2 = stk2.top();
        stk1.pop();
        stk2.pop();
        int curS = cur1 + cur2 + carry;
        carry = curS / 10;
        resStk.push(curS % 10);
    }
    while (!stk1.empty()) {
        int cur1 = stk1.top();
        stk1.pop();
        int curS = cur1 + carry;
        carry = curS / 10;
        resStk.push(curS % 10);
    }
    while (!stk2.empty()) {
        int cur2 = stk2.top();
        stk2.pop();
        int curS = cur2 + carry;
        carry = curS / 10;
        resStk.push(curS % 10);
    }
    if (carry) {
        resStk.push(1);
    }

    ListNode* dummyHead = new ListNode(-1);
    ListNode* curNode = dummyHead;
    while (!resStk.empty()) {
        ListNode* newNode = new ListNode(resStk.top());
        resStk.pop();
        curNode->next = newNode;
        curNode = curNode->next;
    }

    return dummyHead->next;
}