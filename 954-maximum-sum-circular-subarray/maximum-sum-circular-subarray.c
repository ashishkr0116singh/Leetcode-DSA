#include <limits.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = 0, maxSum = INT_MIN;
    int currMin = 0, minSum = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        totalSum += num;

        // Kadane’s for max subarray
        currMax = (currMax + num > num) ? currMax + num : num;
        maxSum = (maxSum > currMax) ? maxSum : currMax;

        // Kadane’s for min subarray
        currMin = (currMin + num < num) ? currMin + num : num;
        minSum = (minSum < currMin) ? minSum : currMin;
    }

    // If all numbers are negative, maxSum is the answer
    if (maxSum < 0) return maxSum;

    // Otherwise, maximum is either normal max or circular max
    return (maxSum > totalSum - minSum) ? maxSum : totalSum - minSum;
}