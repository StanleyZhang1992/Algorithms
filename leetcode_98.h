#pragma once

/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

using namespace std;

/*
use dfs
the trick here is to pass along the min-max range as doing the dfs
discriminate when min-max has null value (i.e. unlimited bound)
discriminate when null children exist
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* node, TreeNode* lower, TreeNode* upper) {
    if (!node)
        return true;
    bool leftIsValid = dfs(node->left, lower, node);
    bool rightIsValid = dfs(node->right, node, upper);
    if (!leftIsValid || !rightIsValid)
        return false;
    if (lower == nullptr && upper == nullptr)
        return true;
    if (upper == nullptr)
        return node->val > lower->val;
    if (lower == nullptr)
        return node->val < upper->val;
    return node->val > lower->val && node->val < upper->val;
}

bool isValidBST(TreeNode* root) {
    return dfs(root, nullptr, nullptr);
}