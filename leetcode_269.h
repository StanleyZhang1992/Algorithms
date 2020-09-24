#pragma once
/*
269. Alien Dictionary

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
]

Output: ""

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, int> preCount;
    for (string s : words) {
        for (char c : s) {
            preCount[c] = 0;
        }
    }
    unordered_map<char, unordered_set<char> > graph;

    for (int i = 0; i < words.size() - 1; ++i) {
        string cur = words[i];
        string next = words[i + 1];
        for (int i = 0; i < cur.size(); ++i) {
            if (i >= next.size()) {
                return "";
            }
            if (cur[i] != next[i]) {
                if (!graph[cur[i]].count(next[i])) {
                    graph[cur[i]].insert(next[i]);
                    preCount[next[i]] += 1;
                }
                break;
            }
            else {
                continue;
            }
        }
    }

    queue<char> q;
    string res;
    for (auto p : preCount) {
        if (p.second == 0) {
            q.push(p.first);
        }
    }
    while (!q.empty()) {
        char curChar = q.front();
        res += curChar;
        q.pop();
        for (char next : graph[curChar]) {
            preCount[next] -= 1;
            if (preCount[next] == 0) {
                q.push(next);
            }
        }
    }

    return (res.size() == preCount.size()) ? res : "";
}