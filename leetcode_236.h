#pragma once
/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/

/*
conditions:
the root is one of the value
either left or right returns nullptr
both children return non-null values
both children return null values
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // edge case
    if (!root || root == p || root == q) {
        return root;
    }

    // main logic
    TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
    if (!leftRes && !rightRes)
        return nullptr;
    if (!leftRes)
        return rightRes;
    if (!rightRes)
        return leftRes;
    return root;
}