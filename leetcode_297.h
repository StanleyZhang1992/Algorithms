#pragma once
/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example:

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

#include<string>
#include<queue>

using namespace std;

/*
use dfs to serialize the tree (inorder traversal)
use similar dfs to deserialize the string
use a queue to store the remaining nodes
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // base case
        if (!root) {
            return "#";
        }
        // recursive case
        string res;
        res += to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        res = res + "," + left + "," + right;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // process the string into a queue of string
        queue<TreeNode*> q;
        string numStr;
        for (char c : data) {
            if (c == '#') {
                q.push(nullptr);
            }
            else if (c == ',') {
                if (numStr.size() > 0) {
                    TreeNode* newNode = new TreeNode(stoi(numStr));
                    q.push(newNode);
                    numStr = "";
                }
            }
            else {
                numStr += c;
            }
        }
        // perform dfs
        return dfs(q);
    }

    TreeNode* dfs(queue<TreeNode*>& q) {
        TreeNode* rootNode = q.front();
        q.pop();
        // base case
        if (!rootNode) {
            return rootNode;
        }
        // recursive case 
        rootNode->left = dfs(q);
        rootNode->right = dfs(q);
        return rootNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));