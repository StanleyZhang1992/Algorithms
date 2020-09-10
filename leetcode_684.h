#pragma once
/*
684. Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
*/
#include<vector>
#include<numeric>
#include<unordered_map>

using namespace std;

class UnionFind {
public:
    class Node {
    public:
        int val;
        Node* parent;
        int rank;

        Node(int val) {
            this->val = val;
            this->parent = this;
            this->rank = 0;
        }
    };

    unordered_map<int, Node*> data;

    UnionFind(vector<int>& nums) {
        for (int n : nums) {
            Node* node = new Node(n);
            data[n] = node;
        }
    }

    Node* findSet(int target) {
        Node* node = data[target];
        return findSet(node);
    }

    Node* findSet(Node* node) {
        if (node->parent == node) {
            return node;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }

    bool unionSets(int i1, int i2) {
        Node* node1 = data[i1];
        Node* node2 = data[i2];
        Node* root1 = findSet(node1);
        Node* root2 = findSet(node2);
        if (root1 == root2) {
            return false;
        }
        if (root1->rank >= root2->rank) {
            if (root1->rank == root2->rank) {
                root1->rank += 1;
            }
            root2->parent = root1;
        }
        else {
            root1->parent = root2;
        }
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int eSize = edges.size();
    vector<int> nums(eSize, 0);
    std::iota(nums.begin(), nums.end(), 1);
    UnionFind uf(nums);

    for (vector<int>& edge : edges) {
        bool success = uf.unionSets(edge[0], edge[1]);
        if (!success) {
            return edge;
        }
    }

    return vector<int>();
}