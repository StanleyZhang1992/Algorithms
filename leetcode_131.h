#pragma once
/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include<vector>
#include<string>

using namespace std;

/*
use each element as starting element, and then iterate over the rest chars to determine if the current string is a valid palindrome, and if so push the current stirng
into the current path, when reaching the end push the path into the result vector
time complexity is O(n^3)
*/
void dfs(int start, vector<string>& path, vector<vector<string> >& res, string& s) {
    int sSize = s.size();
    // base case
    if (start >= sSize) {
        res.push_back(path);
        return;
    }
    // recursive case
    for (int i = start; i < sSize; ++i) {
        string curStr = string(s.begin() + start, s.begin() + i + 1);
        if (isPalindrome(curStr)) {
            path.push_back(curStr);
            dfs(i + 1, path, res, s);
            path.pop_back();
        }
    }
}

bool isPalindrome(string& s) {
    int sSize = s.size();
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;
}

vector<vector<string>> partition(string s) {
    vector<vector<string> > res;
    int sSize = s.size();
    vector<string> path;
    dfs(0, path, res, s);
    return res;
}