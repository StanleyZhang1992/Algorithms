#pragma once
/*
1239. Maximum Length of a Concatenated String with Unique Characters

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.



Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26


Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/
#include<vector>
#include<unordered_set>

using namespace std;

int maxLength(vector<string>& arr) {
    int res = 0;
    unordered_set<char> cache;
    dfs(0, "", "", arr, res, cache);
    return res;
}

void dfs(int start, string path, string added, vector<string>& arr, int& res, unordered_set<char>& cache) {
    // base case
    path += added;
    if (path.size() > res)
        res = path.size();
    int aSize = arr.size();
    if (start >= aSize) {
        return;
    }

    // recursive case
    for (int idx = start; idx < aSize; ++idx) {
        unordered_set<char> temp_cache;
        string added = arr[idx];
        bool jump = false;
        for (char c : added) {
            if (cache.count(c)) {
                jump = true;
                break;
            }
        }
        if (jump) {
            continue;
        }
        else {
            for (char c : added) {
                if (!temp_cache.count(c)) {
                    temp_cache.insert(c);
                }
                else {
                    jump = true;
                    break;
                }
            }
        }
        if (jump) {
            continue;
        }
        else {
            cache.insert(temp_cache.begin(), temp_cache.end());
        }
        dfs(idx + 1, path, added, arr, res, cache);
        for (char c : added) {
            cache.erase(c);
        }
    }
}