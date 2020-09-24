#pragma once
/*
472. Concatenated Words

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/
#include<vector>
#include<string>

using namespace std;

class Trie {
public:
    // member variables
    bool isWord;
    vector<Trie*> next;
    // member functions
    Trie() {
        isWord = false;
        next = vector<Trie*>(26, nullptr);
    }

    void insert(string& word) {
        Trie* cur = this;
        for (char c : word) {
            if (cur->next[c - 'a']) {
                cur = cur->next[c - 'a'];
            }
            else {
                Trie* newTrie = new Trie();
                cur->next[c - 'a'] = newTrie;
                cur = cur->next[c - 'a'];
            }
        }
        cur->isWord = true;
    }

    bool search(string& word, int idx, int count) {
        Trie* cur = this;
        for (int i = idx; i < word.size(); ++i) {
            char curChar = word[i];
            if (cur->next[curChar - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[curChar - 'a'];
            if (cur->isWord) {
                if (i == word.size() - 1) {
                    return count > 0;
                }
                else {
                    if (this->search(word, i + 1, count + 1))
                        return true;
                }
            }
        }
        return false;
    }
};

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    Trie* trie = new Trie();
    for (string word : words) {
        trie->insert(word);
    }
    vector<string> res;
    for (string word : words) {
        if (trie->search(word, 0, 0)) {
            res.push_back(word);
        }
    }
    return res;
}