#pragma once
/*
680. Valid Palindrome II

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
#include<string>

using namespace std;

bool validPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            return (isPalindrome(start + 1, end, s) || isPalindrome(start, end - 1, s));
        }
        start += 1;
        end -= 1;
    }
    return true;
}

bool isPalindrome(int start, int end, string& s) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}