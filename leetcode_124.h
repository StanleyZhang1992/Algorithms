#pragma once
/*
124. Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
#include<algorithm>

using namespace std;

/*
update res as a reference
return of the dfs function should be sum of either side in order to be combined with the root node to form a path
O(n) time complexity
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* node, int& res) {
    // base case
    if (!node) {
        return 0;
    }
    // recursive case
    int leftMax = dfs(node->left, res);
    int rightMax = dfs(node->right, res);
    // temp contains the current root node plus either child tree
    int temp = max(leftMax, rightMax) + node->val;
    // curMax doesn't consider both chlidren at the same time, or the node itself
    int curMax = max(temp, node->val);
    // res considers all four cases
    res = max(max(curMax, leftMax + rightMax + node->val), res);
    return curMax;
}

int maxPathSum(TreeNode* root) {
    int res = -INT_MAX;
    dfs(root, res);
    return res;
}