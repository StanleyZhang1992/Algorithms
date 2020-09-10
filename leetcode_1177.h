#pragma once
/*
1177. Can Make Palindrome from Substring

Given a string s, we make queries on substrings of s.

For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right], and then choose up to k of them to replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.

Return an array answer[], where answer[i] is the result of the i-th query queries[i].

Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa", and k = 2, we can only replace two of the letters.  (Also, note that the initial string s is never modified by any query.)



Example :

Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0] : substring = "d", is palidrome.
queries[1] : substring = "bc", is not palidrome.
queries[2] : substring = "abcd", is not palidrome after replacing only 1 character.
queries[3] : substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.


Constraints:

1 <= s.length, queries.length <= 10^5
0 <= queries[i][0] <= queries[i][1] < s.length
0 <= queries[i][2] <= s.length
s only contains lowercase English letters.
*/
#include<string>
#include<vector>

using namespace std;

/*
use a hashtable to store pre-counts
O(n) time and space
*/
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<bool> res;
    vector<vector<int> > cache(s.size(), vector<int>(26, 0));
    for (int i = 0; i < s.size(); ++i) {
        char cur_char = s[i] - 'a';
        if (i == 0) {
            cache[i][cur_char] += 1;
        }
        else {
            cache[i] = vector<int>(cache[i - 1].begin(), cache[i - 1].end());
            cache[i][cur_char] += 1;
        }
    }
    for (int i = 0; i < queries.size(); ++i) {
        res.push_back(checkSubstr(s, cache, queries, i));
    }
    return res;
}

bool checkSubstr(string& s, vector<vector<int> >& cache, vector<vector<int> >& queries, int idx) {
    int start = queries[idx][0];
    int end = queries[idx][1];
    vector<int> content_end = cache[end];
    vector<int> content_start = cache[start];
    vector<int> content_substr = vector<int>(26, 0);
    for (int i = 0; i < 26; ++i) {
        content_substr[i] = content_end[i] - content_start[i];
    }
    int start_char = s[start] - 'a';
    content_substr[start_char] += 1;
    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if (content_substr[i] % 2) {
            count += 1;
        }
    }
    int k = queries[idx][2];
    return (k >= count / 2) ? true : false;
}