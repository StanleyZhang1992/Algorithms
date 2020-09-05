#pragma once
/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
#include<vector>

using namespace std;

/*
use dfs to recursively recovert the tree
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* dfs(int p_start, int p_end, int i_start, int i_end, vector<int>& preorder,
    vector<int>& inorder) {
    // base case
    if (p_start > p_end || i_start > i_end) {
        return nullptr;
    }
    // recursive call
    TreeNode* newNode = new TreeNode(preorder[p_start]);
    // find pivot index
    int iSize = inorder.size();
    int pivot = 0;
    for (; pivot < iSize; ++pivot) {
        if (inorder[pivot] == preorder[p_start]) {
            break;
        }
    }
    newNode->left = dfs(p_start + 1, p_start - i_start + pivot, i_start, pivot - 1, preorder, inorder);
    newNode->right = dfs(p_start - i_start + pivot + 1, p_end, pivot + 1, i_end, preorder, inorder);
    return newNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pSize = preorder.size();
    int iSize = inorder.size();
    TreeNode* root = dfs(0, pSize - 1, 0, iSize - 1, preorder, inorder);
    return root;
}