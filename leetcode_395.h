#pragma once
/*
395. Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
use sliding window technique
iterate the array only once
O(n) time complexity
*/
int longestSubstring(string s, int k) {
    // base case
    int sSize = s.size();
    if (sSize == 0) {
        return 0;
    }

    // main logic
    unordered_map<char, int> lookup;
    for (char c : s) {
        lookup[c] += 1;
    }

    // whole string
    bool isValid = true;
    for (auto p : lookup) {
        if (p.second < k) {
            isValid = false;
            break;
        }
    }
    if (isValid) {
        return sSize;
    }

    int start = 0;
    int end = 0;
    int res = 0;
    while (end < sSize) {
        if (lookup[s[end]] < k) {
            string part = string(s.begin() + start, s.begin() + end);
            res = max(res, longestSubstring(part, k));
            start = end + 1;
        }
        end += 1;
    }
    string part = string(s.begin() + start, s.end());
    res = max(res, longestSubstring(part, k));
    return res;
}