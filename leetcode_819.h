#pragma once
/*
819. Most Common Word

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.



Example:

Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    vector<string> strs;

    for (char& c : paragraph) {
        c = isalpha(c) ? c : ' ';
    }

    stringstream ss(paragraph);
    string str;
    while (ss >> str) {
        strs.push_back(str);
    }

    for (string& str : strs) {
        for (int i = 0; i < str.size(); ++i) {
            if (isalpha(str[i])) {
                str[i] = tolower(str[i]);
            }
            else {
                str.erase(str.begin() + i);
            }
        }
    }

    unordered_set<string> ban;
    for (string str : banned) {
        ban.insert(str);
    }
    unordered_map<string, int> count;
    for (string str : strs) {
        if (!ban.count(str))
            count[str] += 1;
    }

    int maxOcur = 0;
    string res;
    for (auto p : count) {
        if (p.second > maxOcur) {
            res = p.first;
        }
        maxOcur = max(maxOcur, p.second);
    }

    return res;
}