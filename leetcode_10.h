#pragma once
#include<vector>
#include<string>

using namespace std;

// implement regex with '*' and '.'
/*
Use dynamic programming to solve the problem.
State is dp[i][j], which means if the first i elements are selected from the string  and first j elements are selected from the pattern, will they match
Time complexity is O(lenS * lenP), so as the space complexity
*/
bool isMatch(string s, string p) {
    int sSize = s.size();
    int pSize = p.size();
    // initialize the dp matrix
    vector<vector<bool> > dp(sSize + 1, vector<bool>(pSize + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= pSize; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
        else {
            dp[0][j] = false;
        }
    }

    for (int i = 1; i <= sSize; ++i) {
        for (int j = 1; j <= pSize; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 2]);
                }
                else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[sSize][pSize];
}