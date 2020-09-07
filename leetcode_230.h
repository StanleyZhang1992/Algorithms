#pragma once
/*
230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/
#include<stack>

using namespace std;

/*
use stack to store nodes (it's a way to implement tree iterators too)
the top node is always guaranteed to hold the minimum node value in the BST
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    if (!root)
        return 0;

    stack<TreeNode*> nodeStack;
    TreeNode* curNode = root;

    while (!nodeStack.empty() || curNode != nullptr) {
        while (curNode) {
            nodeStack.push(curNode);
            curNode = curNode->left;
        }
        TreeNode* curMinNode = nodeStack.top();
        k -= 1;
        if (k == 0) {
            return curMinNode->val;
        }
        nodeStack.pop();
        curNode = curMinNode->right;
    }

    return -1;
}