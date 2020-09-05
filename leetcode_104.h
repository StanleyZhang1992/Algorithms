#pragma once
/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/
#include<queue>

using namespace std;

/*
use either dfs or bfs to traverse the tree
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    int depth = 0;
    if (!root)
        return depth;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        depth += 1;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
        }
    }

    return depth;
}