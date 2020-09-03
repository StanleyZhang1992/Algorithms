#pragma once

/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<char, vector<char> > table;

/*
Use classic depth first search
Time complexity is O(N^k), N is the longest string a number corresponds to, k is the length of the given string
Factorial complexity
*/
void dfs(string& path, vector<string>& res, int idx, string& digits) {
    // base case
    if (path.size() == digits.size()) {
        res.push_back(path);
        return;
    }
    // recursive case
    char curDigit = digits[idx];
    for (char c : table[curDigit]) {
        path += c;
        dfs(path, res, idx + 1, digits);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
        return vector<string>{};

    table = unordered_map<char, vector<char> >{
       {'2', vector<char>{'a', 'b', 'c'}},
       {'3', vector<char>{'d', 'e', 'f'}},
       {'4', vector<char>{'g', 'h', 'i'}},
       {'5', vector<char>{'j', 'k', 'l'}},
       {'6', vector<char>{'m', 'n', 'o'}},
       {'7', vector<char>{'p', 'q', 'r', 's'}},
       {'8', vector<char>{'t', 'u', 'v'}},
       {'9', vector<char>{'w', 'x', 'y', 'z'}}
    };

    vector<string> res;
    string path = "";
    dfs(path, res, 0, digits);
    return res;
}