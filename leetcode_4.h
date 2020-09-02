#pragma once
#include<vector>
#include<algorithm>

using namespace std;

// find the median of two arrays if they are merged
/*
The intuitive way is to merge two arrays first and then find the median.
The optimal approach is to split the first and second arrays and find the median directly.
Time complexity is O(log(min(len1, len2)))
The tricky part is when one array can't be split in the middle, but rather at either side.
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1Size = nums1.size();
    int n2Size = nums2.size();
    // binary search on the shorter array
    if (n1Size > n2Size) {
        return findMedianSortedArrays(nums2, nums1);
    }

    // when nums1 is empty
    int totalSize = n1Size + n2Size;
    if (n1Size == 0) {
        if (n2Size == 0)
            return 0;
        if (n2Size % 2) {
            return nums2[n2Size / 2];
        }
        else {
            return ((double)(nums2[n2Size / 2] + nums2[n2Size / 2 - 1])) / 2;
        }
    }

    // normal case
    int n1_start = 0;
    int n1_end = n1Size;
    while (n1_start <= n1_end) {
        int n1_cur = n1_start + (n1_end - n1_start) / 2;
        int n2_cur = (totalSize + 1) / 2 - n1_cur;

        int n1_left = (n1_cur == 0) ? INT_MIN : nums1[n1_cur - 1];
        int n1_right = (n1_cur == n1Size) ? INT_MAX : nums1[n1_cur];
        int n2_left = (n2_cur == 0) ? INT_MIN : nums2[n2_cur - 1];
        int n2_right = (n2_cur == n2Size) ? INT_MAX : nums2[n2_cur];

        if (n1_left <= n2_right && n2_left <= n1_right) {
            if (totalSize % 2) {
                return max(n1_left, n2_left);
            }
            else {
                return ((double)(max(n1_left, n2_left) + min(n1_right, n2_right))) / 2;
            }
        }
        else if (n1_left > n2_right) {
            n1_end = n1_cur - 1;
        }
        else {
            n1_start = n1_cur + 1;
        }
    }

    return -1;
}