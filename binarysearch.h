#pragma once
#include<vector>

// binary search algorithm
int binarySearch(std::vector<int>& nums, int target) {
	// edge case
	if (nums.size() == 0)
		return -1;

	// main logic
	int left = 0;
	int right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return (nums[left]) == target ? left : -1;
}