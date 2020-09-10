#pragma once
/*
1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1.



Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:



Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0


Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.
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

int makeConnected(int n, vector<vector<int>>& connections) {
    int requiredNum = n - 1;
    int cSize = connections.size();
    if (cSize < n - 1) {
        return -1;
    }

    vector<int> nums(n, 0);
    std::iota(nums.begin(), nums.end(), 0);
    UnionFind uf(nums);

    for (vector<int>& cnt : connections) {
        uf.unionSets(cnt[0], cnt[1]);
    }

    unordered_map<UnionFind::Node*, vector<UnionFind::Node*> > cache;
    for (int i = 0; i < n; ++i) {
        UnionFind::Node* node = uf.data[i];
        UnionFind::Node* root = uf.findSet(i);
        cache[root].push_back(node);
    }

    int components = cache.size();
    return components - 1;
}