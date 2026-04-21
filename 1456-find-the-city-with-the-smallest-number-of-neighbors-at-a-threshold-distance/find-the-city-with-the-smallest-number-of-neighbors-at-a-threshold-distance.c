/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    // Initialize distance matrix
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX / 2; // avoid overflow
        }
    }

    // Fill in edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd–Warshall: compute all-pairs shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Find city with smallest reachable neighbors
    int minCount = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        // If tie, choose the city with larger index
        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);

    return resultCity;
}
