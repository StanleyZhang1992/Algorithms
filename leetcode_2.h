#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// add two numbers expressed as linked lists
/*
The intuitive way to do this is to convert two linked lists into two integers, perform addition and convert the result back to a linked list
However, the problem here is that the number can be very large so even long long type cannot hold the number
As a result, we do addition in the linked list form
Note that we use the concept of carry here to deal with sum larger than 10
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;

    int carry = 0;
    while (l1 && l2) {
        int cur = l1->val + l2->val + carry;
        carry = cur / 10;
        int val = cur % 10;
        ListNode* newNode = new ListNode(val);
        node->next = newNode;
        node = node->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        int cur = l1->val + carry;
        carry = cur / 10;
        int val = cur % 10;
        ListNode* newNode = new ListNode(val);
        node->next = newNode;
        node = node->next;
        l1 = l1->next;
    }
    while (l2) {
        int cur = l2->val + carry;
        carry = cur / 10;
        int val = cur % 10;
        ListNode* newNode = new ListNode(val);
        node->next = newNode;
        node = node->next;
        l2 = l2->next;
    }
    if (carry == 1) {
        ListNode* newNode = new ListNode(1);
        node->next = newNode;
    }
    return dummyHead->next;
}