#pragma once
/*
1520. Maximum Number of Non-Overlapping Substrings
Hard

264

36

Add to List

Share
Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.



Example 1:

Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.


Constraints:

1 <= s.length <= 10^5
s contains only lowercase English letters.
*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> res;
        unordered_map<char, int> lastIdx;
        unordered_map<char, int> firstIdx;
        for (int i = 0; i < s.size(); ++i) {
            lastIdx[s[i]] = i;
            if (!firstIdx.count(s[i])) {
                firstIdx[s[i]] = i;
            }
        }
        map<int, char> lastIdxToChar;
        for (pair<char, int> p : lastIdx) {
            lastIdxToChar[p.second] = p.first;
        }

        int cutoffPos = -1;
        for (pair<int, char> p : lastIdxToChar) {
            int end = p.first;
            int start = firstIdx[p.second];
            int right = end;
            int left = start;
            while (right > left) {
                char cur = s[right];
                if (lastIdx[cur] > end || right == cutoffPos) {
                    break;
                }
                left = min(left, firstIdx[cur]);
                right -= 1;
            }
            if (left == right) {
                res.push_back(string(s.begin() + right, s.begin() + end + 1));
                cutoffPos = right;
            }
        }

        return res;
    }
};