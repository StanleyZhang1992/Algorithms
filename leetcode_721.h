#pragma once
/*
721. Accounts Merge
Medium

1662

326

Add to List

Share
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input:
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/

class Solution {
public:
    class UnionFind {
    public:
        class Node {
        public:
            string val;
            Node* parent;
            int rank;

            Node(string val) {
                this->val = val;
                this->parent = this;
                this->rank = 0;
            }
        };

        unordered_map<string, Node*> data;

        UnionFind(vector<string>& nums) {
            for (string n : nums) {
                Node* node = new Node(n);
                data[n] = node;
            }
        }

        Node* findSet(string target) {
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

        bool unionSets(string i1, string i2) {
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_set<string> emails;

        for (vector<string>& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                string email = account[i];
                if (!emails.count(email)) {
                    emails.insert(email);
                    emailToName[email] = name;
                }
            }
        }

        vector<string> emails_vec = vector<string>(emails.begin(), emails.end());
        UnionFind uf(emails_vec);

        for (vector<string>& account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                string cur = account[i];
                string prev = account[i - 1];
                uf.unionSets(cur, prev);
            }
        }

        map<UnionFind::Node*, vector<string> > components;
        for (string email : emails) {
            UnionFind::Node* s = uf.findSet(email);
            components[s].push_back(email);
        }

        vector<vector<string> > res(components.size(), vector<string>());
        int i = 0;
        for (auto p : components) {
            res[i].push_back(emailToName[p.first->val]);
            for (string email : p.second) {
                res[i].push_back(email);
            }
            i += 1;
        }
        for (vector<string>& item : res) {
            std::sort(item.begin() + 1, item.end());
        }

        return res;
    }
};