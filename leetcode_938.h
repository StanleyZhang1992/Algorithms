#pragma once
/*
938. Range Sum of BST

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.



Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23


Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) {
        return 0;
    }
    int res = 0;
    dfs(root, L, R, res);
    return res;
}

void dfs(TreeNode* node, int L, int R, int& res) {
    if (!node) {
        return;
    }
    if (node->val >= L && node->val <= R) {
        res += node->val;
    }
    if (node->val < R) {
        dfs(node->right, L, R, res);
    }
    if (node->val > L) {
        dfs(node->left, L, R, res);
    }
}