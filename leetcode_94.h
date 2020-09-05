#pragma once

/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include<vector>

using namespace std;

/*
use recursive method or iterative method to achieve O(n) time, n is the number of nodes of the tree
iterative method is basically manually building the stack that the recursive method implicitly builds
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(vector<int>& res, TreeNode* node) {
    // base case
    if (!node)
        return;
    // recursive call
    dfs(res, node->left);
    res.push_back(node->val);
    dfs(res, node->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(res, root);
    return res;
}