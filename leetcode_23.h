#pragma once
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// given k linked lists, merge them into one sorted linked list
/*
The intuitive way is to combine them all together and then sort them, and finally convert them back into one linked list
The time complexity of doing this is O(log(len)*len)
A better approach is to use priority queue to construct the linked list one node by another
The complexity of doing this is O(logk * kN), where k is the number of linked lists and N is the longest linked list
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    auto myComp = [](ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(myComp)> pq(myComp);
    for (ListNode* head : lists) {
        if (head) {
            pq.push(head);
        }
    }
    while (!pq.empty()) {
        ListNode* pqNode = pq.top();
        pq.pop();
        cur->next = pqNode;
        if (pqNode->next) {
            pq.push(pqNode->next);
        }
        cur = cur->next;
    }
    return dummyHead->next;
}