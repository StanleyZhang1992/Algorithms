#pragma once

/*
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
#include<vector>
#include<string>

using namespace std;

/*
treat 0 and other digits differently
use dynamic programming
time complexity is O(n)
*/
int numDecodings(string s) {
    // edge case
    if (s.size() == 0)
        return 0;
    if (s[0] == '0')
        return 0;
    // main logic
    int sSize = s.size();
    vector<int> dp(sSize + 1, 1);
    dp[0] = 1;
    dp[1] = 1;
    s.insert(s.begin(), '#');

    for (int i = 2; i <= sSize; ++i) {
        string cur = string(s.begin() + i - 1, s.begin() + i + 1);
        int curInt = stoi(cur);
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                dp[i] = dp[i - 2];
            else
                return 0;
        }
        else {
            if (curInt > 10 && curInt <= 26)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
    }

    return dp[sSize];
}