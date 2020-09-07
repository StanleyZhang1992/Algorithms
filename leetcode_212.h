#pragma once
/*
212. Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
#include<vector>
#include<string>

using namespace std;

/*
essentially this is a "prefix searching" problem
so it is very suitable to be solved by a trie data structure
dfs over the entire board and each time recursively search starting from the current element and look if current prefix exists in the trie
if not return immediately, otherwise continue search, and if there a word is found, then push it to the res vector
*/
class Solution {
public:
    // inner Trie class
    class TrieDict {
    public:
        // TrieNode class
        class TrieNode {
        public:
            vector<TrieNode*> next;
            string word;

            TrieNode() {
                word = "";
                next = vector<TrieNode*>(26, nullptr);
            }
        };
        TrieNode* root;

        TrieDict() {
            root = new TrieNode();
        }

        void addWord(string added) {
            TrieNode* node = root;
            for (char c : added) {
                if (node->next[c - 'a'] == nullptr) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->word = added;
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // edge case
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0) {
            return res;
        }

        // main logic
        TrieDict* trieDict = new TrieDict();
        for (string s : words) {
            trieDict->addWord(s);
        }

        TrieDict::TrieNode* trieRoot = trieDict->root;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char c = board[i][j];
                if (trieRoot->next[c - 'a'] == nullptr)
                    continue;
                else
                    dfs(i, j, trieRoot, res, board);
            }
        }
        return res;
    }

    void dfs(int row, int col, TrieDict::TrieNode* node, vector<string>& res, vector<vector<char> >& board) {
        // base case
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return;
        }
        char curChar = board[row][col];

        if (board[row][col] == '#')
            return;
        if (node->next[curChar - 'a'] == nullptr)
            return;
        node = node->next[curChar - 'a'];
        if (node->word.size() != 0) {
            res.push_back(node->word);
            node->word = "";
        }
        // recursive case

        board[row][col] = '#';
        dfs(row - 1, col, node, res, board);
        dfs(row + 1, col, node, res, board);
        dfs(row, col - 1, node, res, board);
        dfs(row, col + 1, node, res, board);
        board[row][col] = curChar;
    }
};