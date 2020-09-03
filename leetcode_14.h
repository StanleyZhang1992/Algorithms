#pragma once
#include<string>
#include<vector>

using namespace std;

// scan over each element in each string, takes O(kN) time. k is the number of arrays, N is the length of the first string
string longestCommonPrefix(vector<string>& strs) {
    // edge case
    if (strs.size() == 0)
        return "";

    string res = "";
    string firstStr = strs[0];
    for (int i = 0; i < firstStr.size(); ++i) {
        char c = firstStr[i];
        for (string curStr : strs) {
            if (i >= curStr.size() || curStr[i] != c) {
                return res;
            }
        }
        res += c;
    }

    return res;
}