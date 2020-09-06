#pragma once
/*
140. Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

/*
dfs with memoization
*/
vector<string> dfs(string& s, int startIdx, std::unordered_set<string>& words, std::unordered_map<int, vector<string> >& records) {
    // base case
    if (startIdx >= s.size()) {
        return vector<string>();
    }
    // recursive case
    if (records.count(startIdx)) {
        return records[startIdx];
    }
    vector<string> res;
    for (int end = startIdx; end < s.size() - 1; ++end) {
        string substr = string(s.begin() + startIdx, s.begin() + end + 1);
        if (words.count(substr)) {
            vector<string> strsFromSec = dfs(s, end + 1, words, records);
            for (string str : strsFromSec) {
                res.push_back(substr + " " + str);
            }
        }
    }
    string substr = string(s.begin() + startIdx, s.end());
    if (words.count(substr)) {
        res.push_back(substr);
    }
    records[startIdx] = res;
    return res;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    std::unordered_set<string> words = std::unordered_set<string>(wordDict.begin(), wordDict.end());
    std::unordered_map<int, vector<string> > records;
    vector<string> res = dfs(s, 0, words, records);
    return res;
}