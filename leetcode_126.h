#pragma once
/*
126. Word Ladder II
Hard

1977

261

Add to List

Share
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet = unordered_set<string>(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string> > graph;
        unordered_set<string> seen;

        queue<string> q;
        q.push(beginWord);

        int steps = 0;
        bool reach = false;
        while (!q.empty()) {
            if (seen.count(endWord)) {
                reach = true;
                break;
            }
            unordered_set<string> curLevel;
            steps += 1;
            int qSize = q.size();
            for (int count = 0; count < qSize; ++count) {
                string cur = q.front();
                string updated = cur;
                q.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    char temp = updated[i];
                    for (int j = 0; j < 26; ++j) {
                        updated[i] = 'a' + j;
                        if (!seen.count(updated) && wordSet.count(updated)) {
                            curLevel.insert(updated);
                            graph[updated].insert(cur);
                            q.push(updated);
                        }
                        else if (updated == endWord) {
                            graph[updated].insert(cur);
                        }
                    }
                    updated[i] = temp;
                }
            }
            seen.insert(curLevel.begin(), curLevel.end());
        }

        vector<vector<string> > res;
        if (reach) {
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, path, res, beginWord, 0, graph, steps);
        }
        for (vector<string>& seq : res) {
            std::reverse(seq.begin(), seq.end());
        }
        return res;
    }

    void dfs(string word, vector<string>& path, vector<vector<string> >& res, string& beginWord, int level, unordered_map<string, unordered_set<string> >& graph, int& steps) {
        // base case
        if (level > steps) {
            return;
        }
        if (word == beginWord) {
            res.push_back(path);
        }

        // recursive case
        for (string nextWord : graph[word]) {
            path.push_back(nextWord);
            dfs(nextWord, path, res, beginWord, level + 1, graph, steps);
            path.pop_back();
        }
    }
};