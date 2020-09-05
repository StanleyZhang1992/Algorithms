#pragma once
/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include<algorithm>

using namespace std;

/*
implement quicksort on linked list
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
    quickSort(head, nullptr);
    return head;
}

void quickSort(ListNode* start, ListNode* end) {
    // base case
    if (start == end)
        return;

    // recursive case
    // partition
    int pivot = start->val;
    ListNode* slow = start;
    ListNode* fast = start->next;
    while (fast != end) {
        if (fast->val < pivot) {
            slow = slow->next;
            swapValue(slow, fast);

        }
        fast = fast->next;
    }
    swapValue(start, slow);
    // DC
    quickSort(start, slow);
    quickSort(slow->next, end);
}

void swapValue(ListNode* n1, ListNode* n2) {
    std::swap(n1->val, n2->val);
}