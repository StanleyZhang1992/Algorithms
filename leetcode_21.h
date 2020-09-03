#pragma once

/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/*
merge two sorted linked lists
the only thing to pay attention here is when one list is done and the other is not
two pointers approach, O(m+n) complexity
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    if (!l1) {
        cur->next = l2;
    }
    else if (!l2) {
        cur->next = l1;
    }
    return dummyHead->next;
}