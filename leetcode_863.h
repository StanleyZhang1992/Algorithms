#pragma once
/*
863. All Nodes Distance K in Binary Tree

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.



Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.


Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
*/
#include<vector>
#include<map>


using namespace std;

map<TreeNode*, TreeNode*> parents;
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    dfs(root, nullptr);

    vector<int> res;
    queue<TreeNode*> q;
    set<TreeNode*> seen;
    q.push(target);
    seen.insert(target);
    seen.insert(nullptr);
    int dist = 0;
    while (!q.empty()) {
        if (dist == K) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                res.push_back(cur->val);
            }
            return res;
        }
        else {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (seen.count(cur->left) == 0) {
                    q.push(cur->left);
                    seen.insert(cur->left);
                }
                if (seen.count(cur->right) == 0) {
                    q.push(cur->right);
                    seen.insert(cur->right);
                }
                if (seen.count(parents[cur]) == 0) {
                    q.push(parents[cur]);
                    seen.insert(parents[cur]);
                }
            }
            dist += 1;
        }
    }
    return res;
}

void dfs(TreeNode* node, TreeNode* parent) {
    // base case
    if (!node) {
        return;
    }
    // recursive case
    parents[node] = parent;
    dfs(node->left, node);
    dfs(node->right, node);
}