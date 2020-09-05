#pragma once
/*
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include<string>
#include<unordered_map>

using namespace std;

/*
use sliding window to achieve O(n) time complexity
*/
string minWindow(string s, string t) {
    // edge case
    if (s.size() == 0 || t.size() == 0) {
        return "";
    }
    // main logic
    int sSize = s.size();

    int curMinLen = INT_MAX;
    int start = 0;
    int end = 0;
    int left = 0;
    int right = 0;
    int matchChars = 0;
    // intialize map
    unordered_map<char, int> lookup;
    for (char c : t) {
        lookup[c] += 1;
    }
    int tSize = 0;
    for (auto p : lookup) {
        tSize += 1;
    }

    while (right < sSize) {
        char curChar = s[right];
        if (lookup.count(curChar)) {
            lookup[curChar] -= 1;
            // matching all done with curChar
            if (lookup[curChar] == 0) {
                matchChars += 1;
            }
        }

        // while string is valid
        while (matchChars == tSize) {
            int curLen = right - left + 1;
            if (curLen < curMinLen) {
                end = right;
                start = left;
                curMinLen = curLen;
            }
            char leftChar = s[left];
            if (lookup.count(leftChar)) {
                lookup[leftChar] += 1;
                if (lookup[leftChar] > 0) {
                    matchChars -= 1;
                }
            }
            left += 1;
        }

        right += 1;
    }

    string res = string(s.begin() + start, s.begin() + end + 1);
    return curMinLen == INT_MAX ? "" : res;
}