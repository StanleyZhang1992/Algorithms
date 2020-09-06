#pragma once
/*
204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
#include<vector>
#include<numeric>

using namespace std;

/*
use the feature of prime numbers to iteratively find the non-prime numbers
*/
int countPrimes(int n) {
    if (n < 2)
        return 0;
    vector<int> cache(n, 1);
    cache[0] = 0;
    cache[1] = 0;
    for (int i = 2; i < n; ++i) {
        int j = i + i;
        while (j < n) {
            if (cache[j]) {
                cache[j] = 0;
            }
            j += i;
        }
    }
    int res = std::accumulate(cache.begin(), cache.end(), 0);
    return res;
}