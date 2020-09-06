#pragma once
/*
179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
use proof-by-contridiction to prove that the result is the largest when there's no pair a-b in the result that can achieve 'ba' > 'ab'
O(nlogn) time
*/
string largestNumber(vector<int>& nums) {

    auto intMerge = [](int i1, int i2) {
        string s1 = std::to_string(i1);
        string s2 = std::to_string(i2);
        string str = s1 + s2;
        return std::stoll(str);
    };

    auto myComp = [intMerge](int i1, int i2) {
        long long res1 = intMerge(i1, i2);
        long long res2 = intMerge(i2, i1);
        return res1 > res2;
    };


    std::sort(nums.begin(), nums.end(), myComp);
    string res;
    for (int i : nums) {
        res += std::to_string(i);
    }
    return res[0] == '0' ? "0" : res;
}