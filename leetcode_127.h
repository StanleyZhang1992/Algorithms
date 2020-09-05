#pragma once

/*
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

/*
use queue to scan words layer by layer
use hashtable to store visited words so that the process doesn't go into endless loop
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
    q.push(beginWord);

    unordered_set<string> avail;
    avail = unordered_set<string>(wordList.begin(), wordList.end());

    int times = 1;
    while (!q.empty()) {
        int qSize = q.size();
        for (int k = 0; k < qSize; ++k) {
            string curWord = q.front();
            if (curWord == endWord) {
                return times;
            }
            q.pop();
            int sSize = curWord.size();
            for (int i = 0; i < sSize; ++i) {
                char c = curWord[i];
                for (int j = 0; j < 26; ++j) {
                    curWord[i] = 'a' + j;
                    if (avail.count(curWord)) {
                        q.push(curWord);
                        avail.erase(curWord);
                    }
                }
                curWord[i] = c;
            }
        }
        times += 1;
    }

    return 0;
}