#pragma once
/*
763. Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.



Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> last_index(26, 0);
    for (int i = 0; i < S.size(); ++i) {
        int curChar = S[i] - 'a';
        last_index[curChar] = i;
    }

    vector<int> res;
    int start = 0;
    int target = 0;
    for (int end = 0; end < S.size(); ++end) {
        int curChar = S[end] - 'a';
        target = max(target, last_index[curChar]);
        if (end == target) {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }

    return res;
}