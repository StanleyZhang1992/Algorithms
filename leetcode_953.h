#pragma once
/*
953. Verifying an Alien Dictionary

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/
#include<vector>
#include<unordered_map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    // build the dictionary
    unordered_map<char, int> dict;
    for (int i = 0; i < order.size(); ++i) {
        dict[order[i]] = i;
    }

    auto inOrder = [&dict](string& w1, string& w2) {
        int idx = 0;
        while (idx < w1.size() && idx < w2.size()) {
            char w1_char = w1[idx];
            char w2_char = w2[idx];
            if (w1_char != w2_char) {
                return dict[w1_char] < dict[w2_char];
            }
            idx += 1;
        }
        return w1.size() <= w2.size();
    };

    for (int i = 1; i < words.size(); ++i) {
        if (!inOrder(words[i - 1], words[i])) {
            return false;
        }
    }
    return true;
}