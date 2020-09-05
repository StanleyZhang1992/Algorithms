#pragma once
/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.
*/

#include<string>

using namespace std;

/*
basic use of two pointers
*/
bool isPalindrome(string s) {
    string goodStr;
    for (char c : s) {
        if (isalnum(c)) {
            goodStr.push_back(tolower(c));
        }
    }
    int gSize = goodStr.size();

    // edge case
    if (gSize == 0)
        return true;

    int left = 0;
    int right = gSize - 1;
    while (left < right) {
        if (goodStr[left] != goodStr[right])
            return false;
        left += 1;
        right -= 1;
    }

    return true;
}