#pragma once
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
The brute force is intuitive but takes O(n^3) time
We can use sliding window to optimize the algorithm so it only takes O(n) time
The hashtable can be used to store the elements within the sliding window
*/
int lengthOfLongestSubstring(string s) {
    int sSize = s.size();
    unordered_set<char> cache;
    int start = 0;
    int end = 0;
    int res = 0;
    while (end < sSize) {
        while (cache.count(s[end])) {
            cache.erase(s[start]);
            start += 1;
        }
        cache.insert(s[end]);
        res = max(res, end - start + 1);
        end += 1;
    }
    return res;
}