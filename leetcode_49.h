#pragma once

/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
sort each element so that we know its anagram is already in the cache
time complexity is O(KNlogN)
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    std::unordered_map<string, vector<string> > cache;
    for (string s : strs) {
        string temp = string(s.begin(), s.end());
        std::sort(temp.begin(), temp.end());
        cache[temp].push_back(s);
    }
    for (auto p : cache) {
        res.push_back(p.second);
    }
    return res;
}