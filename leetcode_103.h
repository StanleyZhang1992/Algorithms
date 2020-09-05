#pragma once

/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
#include<vector>
#include<queue>

using namespace std;

/*
similar to level order traversal
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root)
        return res;

    queue<TreeNode*> q;
    q.push(root);

    int levelNum = 0;
    while (!q.empty()) {
        int qSize = q.size();
        vector<int> curLevel;
        // operation on each level
        for (int i = 0; i < qSize; ++i) {
            TreeNode* curNode = q.front();
            curLevel.push_back(curNode->val);
            q.pop();
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
        }
        if (levelNum % 2 == 1) {
            std::reverse(curLevel.begin(), curLevel.end());
        }
        res.push_back(curLevel);
        levelNum += 1;
    }

    return res;
}