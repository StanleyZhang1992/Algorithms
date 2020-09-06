#pragma once
/*
206. Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/*
use the classic prev-cur-next triplet pointers
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    // edge case
    if (head == nullptr)
        return head;

    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = cur->next;
    while (next) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }

    cur->next = prev;
    return cur;
}