#pragma once
/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include<stack>
#include<queue>

using namespace std;

/*
slow-fast pointer to find the medium of the linked list
then use stack and queue to store elements in reversed order
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    // edge case
    if (!head) {
        return true;
    }

    // main logic
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) {
        slow = slow->next;
    }

    stack<ListNode*> s;
    queue<ListNode*> q;
    while (slow) {
        s.push(head);
        q.push(slow);
        head = head->next;
        slow = slow->next;
    }

    while (!s.empty()) {
        ListNode* stackNode = s.top();
        s.pop();
        ListNode* queueNode = q.front();
        q.pop();
        if (stackNode->val != queueNode->val)
            return false;
    }

    return true;
}