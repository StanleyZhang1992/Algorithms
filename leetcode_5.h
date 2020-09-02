#pragma once
#include<string>
#include<vector>

using namespace std;

/*
We can use dynamic programming to solve the problem.
If s[i] == s[j], then we only have to consider if s[i+1, j-1] is a palindrome string, which we can get from previous computation
Time complexity is O(len * len), so as space complexity
*/
string longestPalindrome(string s) {
    // edge case
    if (s.size() == 0)
        return "";

    // main logic
    int res = 1;
    int sSize = s.size();
    int start = 0;
    int end = 0;
    vector<vector<bool> > dp(sSize, vector<bool>(sSize, true));
    for (int j = 0; j < sSize; ++j) {
        for (int i = j - 1; i >= 0; --i) {
            if (s[i] != s[j]) {
                dp[i][j] = false;
            }
            else {
                dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j]) {
                if (j - i + 1 > res) {
                    res = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }
    return string(s.begin() + start, s.begin() + end + 1);
}