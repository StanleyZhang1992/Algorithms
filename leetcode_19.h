#pragma once

/*
19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/*
Use dummyHead, use prev pointer, use slow-fast pointer.
time complexity is O(n)
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode* cur = head;
    ListNode* fast = head;
    ListNode* prev = dummyHead;
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        cur = cur->next;
        prev = prev->next;
    }
    prev->next = cur->next;
    return dummyHead->next;
}