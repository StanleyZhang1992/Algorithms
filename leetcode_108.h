#pragma once
/*
108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
#include<vector>

using namespace std;

/*
use dfs to deal with the array part by part
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* dfs(int start, int end, vector<int>& nums) {
    // base case
    if (start > end)
        return nullptr;
    // recursive case
    int mid = start + (end - start) / 2;
    TreeNode* newNode = new TreeNode(nums[mid]);
    newNode->left = dfs(start, mid - 1, nums);
    newNode->right = dfs(mid + 1, end, nums);
    return newNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    // null case
    if (nums.size() == 0)
        return nullptr;

    // main logic
    TreeNode* root = dfs(0, nums.size() - 1, nums);
    return root;
}