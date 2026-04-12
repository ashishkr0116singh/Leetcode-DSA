/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    bool* inMST = (bool*)calloc(n, sizeof(bool));
    int* minDist = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    int result = 0;
    minDist[0] = 0; // start from point 0

    for (int i = 0; i < n; i++) {
        int u = -1;
        int minVal = INT_MAX;

        // Pick the next point not in MST with smallest distance
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                u = j;
            }
        }

        inMST[u] = true;
        result += minVal;

        // Update distances to remaining points
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(inMST);
    free(minDist);
    return result;
}
