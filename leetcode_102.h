#pragma once

/*
102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include<vector>
#include<queue>

using namespace std;

/*
manually main a queue structure to achieve level order traversal
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root)
        return res;

    // initialize queue
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        // current level
        vector<int> curLevel;
        int curSize = q.size();
        for (int i = 0; i < curSize; ++i) {
            TreeNode* curNode = q.front();
            q.pop();
            curLevel.push_back(curNode->val);
            if (curNode->left) {
                q.push(curNode->left);
            }
            if (curNode->right) {
                q.push(curNode->right);
            }
        }
        res.push_back(curLevel);
    }

    return res;
}