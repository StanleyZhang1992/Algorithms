#pragma once
/*
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include<vector>
#include<unordered_set>

using namespace std;

/*
use dynamic programming to store the possible breaks
time complexity is O(n^2)
*/
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> cache{ wordDict.begin(), wordDict.end() };
    int sSize = s.size();
    vector<bool> dp(sSize, false);
    for (int i = 0; i < sSize; ++i) {
        string sub = string(s.begin(), s.begin() + i + 1);
        if (cache.count(sub))
            dp[i] = true;
    }
    for (int j = 0; j < sSize; ++j) {
        for (int i = j - 1; i >= 0; --i) {
            string secSub = string(s.begin() + i + 1, s.begin() + j + 1);
            if (dp[i] && cache.count(secSub))
                dp[j] = true;
        }
    }

    return dp[sSize - 1];
}