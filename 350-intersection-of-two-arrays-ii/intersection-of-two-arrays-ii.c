#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    // Allocate result array (max possible size = min(nums1Size, nums2Size))
    int *res = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i = 0, j = 0, k = 0;

    // Two-pointer traversal
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            res[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    *returnSize = k;
    return res;
}