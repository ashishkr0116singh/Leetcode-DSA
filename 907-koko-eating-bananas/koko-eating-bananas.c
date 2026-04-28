/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

long long hoursNeeded(int* piles, int pilesSize, int speed) {
    long long hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + speed - 1) / speed; // ceil division
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) right = piles[i]; // max pile size
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (hoursNeeded(piles, pilesSize, mid) <= h) {
            right = mid; // can eat within h hours, try smaller speed
        } else {
            left = mid + 1; // need faster speed
        }
    }

    return left;
}
