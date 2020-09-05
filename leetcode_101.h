#pragma once

/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3


Follow up: Solve it both recursively and iteratively.
*/

/*
use dfs to recursively check each pair
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode* n1, TreeNode* n2) {
    if (n1 && n2) {
        return (n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left));
    }
    else {
        return n1 == n2;
    }
}

bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}