#pragma once
/*
454. 4Sum II

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
#include<vector>
#include<unordered_map>

using namespace std;

/*
brute force takes O(n^4) time
use hashtable to store the sum of the first matrics' elements
reduce time complexity to O(n^2)
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> lookupAB;
    int ASize = A.size();
    int BSize = B.size();
    int CSize = C.size();
    int DSize = D.size();
    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < BSize; ++j) {
            int s = A[i] + B[j];
            lookupAB[s] += 1;
        }
    }
    int res = 0;
    for (int i = 0; i < CSize; ++i) {
        for (int j = 0; j < DSize; ++j) {
            int s = -(C[i] + D[j]);
            if (lookupAB.count(s)) {
                res += lookupAB[s];
            }
        }
    }
    return res;
}