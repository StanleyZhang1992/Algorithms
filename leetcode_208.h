#pragma once
/*
208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
#include<vector>
#include<string>

using namespace std;

/*
each Trie node has a hashtable to store the 26 letters to check if there is a following letter
and also a True/False flag to determine if this is the end of a word
very fast lookup for if a prefix exists
deletion can be done in a recursive manner
*/
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        next = vector<Trie*>(26, nullptr);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr)
                return false;
            else {
                node = node->next[c - 'a'];
            }
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->next[c - 'a'] == nullptr)
                return false;
            else
                node = node->next[c - 'a'];
        }
        return true;
    }
private:
    bool isEnd;
    vector<Trie*> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */