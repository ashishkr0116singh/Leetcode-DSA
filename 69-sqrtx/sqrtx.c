/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x / 2, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sq = mid * mid;

        if (sq == x) {
            return (int)mid; // perfect square
        } else if (sq < x) {
            ans = (int)mid;  // store possible answer
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans; // integer part of sqrt(x)
}
