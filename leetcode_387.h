#pragma once
/*
387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.


Note: You may assume the string contains only lowercase English letters.
*/
#include<string>
#include<unordered_map>

using namespace std;

/*
basic use of hashtable
*/
int firstUniqChar(string s) {
    unordered_map<char, int> lookup;
    for (char c : s) {
        lookup[c] += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (lookup[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}