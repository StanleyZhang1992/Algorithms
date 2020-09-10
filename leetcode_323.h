#pragma once
/*
323. Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
#include<unordered_map>
#include<vector>
#include<numeric>

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

int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> nums(n, 0);
    std::iota(nums.begin(), nums.end(), 0);
    UnionFind uf(nums);

    for (vector<int>& edge : edges) {
        uf.unionSets(edge[0], edge[1]);
    }

    unordered_map<UnionFind::Node*, vector<UnionFind::Node*> > cache;
    for (int i = 0; i < n; ++i) {
        UnionFind::Node* root = uf.findSet(i);
        cache[root].push_back(uf.data[i]);
    }

    return cache.size();
}