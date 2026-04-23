/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // found target
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If not found, left is the correct insert position
    return left;
}
