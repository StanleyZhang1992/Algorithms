#pragma once
/*
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include<vector>
#include<unordered_set>

using namespace std;

/*
use sorting can put the same values together and achieve O(nlogn) time
use hashtable can achieve O(n) time but O(n) space too
*/
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int n : nums) {
        if (seen.count(n)) {
            return true;
        }
        else {
            seen.insert(n);
        }
    }
    return false;
}