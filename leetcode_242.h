#pragma once
/*
242. Valid Anagram

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
#include<unordered_map>

using namespace std;

/*
use hashtable to store the number of each element in the string
*/
bool isAnagram(string s, string t) {
    unordered_map<char, int> cache;
    for (char c : s) {
        cache[c] += 1;
    }
    for (char c : t) {
        if (!cache.count(c))
            return false;
        else {
            cache[c] -= 1;
        }
    }
    for (auto p : cache) {
        if (p.second != 0)
            return false;
    }
    return true;
}