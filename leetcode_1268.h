#pragma once
/*
1268. Search Suggestions System
Medium

727

83

Add to List

Share
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed.



Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]


Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.
*/

class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> next;
        bool isWord;
        TrieNode() {
            next = vector<TrieNode*>(26, nullptr);
            isWord = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void addWord(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->next[idx]) {
                    TrieNode* newNode = new TrieNode();
                    node->next[idx] = newNode;
                }
                node = node->next[idx];
            }
            node->isWord = true;
        }

        bool searchPrefix(TrieNode* node, string& prefix) {
            for (char c : prefix) {
                int idx = c - 'a';
                if (!node->next[idx]) {
                    return false;
                }
                else {
                    node = node->next[idx];
                }
            }
            return true;
        }

        vector<string> searchWords(TrieNode* node, string& prefix) {
            for (int i = 0; i < prefix.size(); ++i) {
                node = node->next[prefix[i] - 'a'];
            }
            vector<string> res;
            dfs(node, res, prefix);
            std::sort(res.begin(), res.end());
            return (res.size() < 3) ? res : vector<string>(res.begin(), res.begin() + 3);
        }

        void dfs(TrieNode* node, vector<string>& res, string& path) {
            if (node->isWord) {
                res.push_back(path);
            }
            for (int i = 0; i < 26; ++i) {
                TrieNode* nextNode = node->next[i];
                char curChar = 'a' + i;
                if (!nextNode) {
                    continue;
                }
                path.push_back(curChar);
                dfs(nextNode, res, path);
                path.pop_back();
            }
        }
    };


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (string word : products) {
            trie.addWord(word);
        }
        vector<vector<string> > res;
        for (int i = 1; i <= searchWord.size(); ++i) {
            string cur = string(searchWord.begin(), searchWord.begin() + i);
            if (trie.searchPrefix(trie.root, cur)) {
                vector<string> curRes = trie.searchWords(trie.root, cur);
                res.push_back(curRes);
            }
            else {
                res.push_back(vector<string>());
            }
        }
        return res;
    }
};