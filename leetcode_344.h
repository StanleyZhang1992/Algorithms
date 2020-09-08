#pragma once
/*
344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
#include<vector>

using namespace std;

/*
two pointers
*/
void reverseString(vector<char>& s) {
    // edge case
    int sSize = s.size();
    if (sSize == 0)
        return;

    // main logic
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left += 1;
        right -= 1;
    }
}