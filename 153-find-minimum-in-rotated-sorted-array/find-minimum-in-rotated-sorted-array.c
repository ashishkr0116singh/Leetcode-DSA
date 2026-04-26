/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum is in the right half
            left = mid + 1;
        } else {
            // Minimum is in the left half (including mid)
            right = mid;
        }
    }

    return nums[left]; // or nums[right], both point to the minimum
}
