/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int node, int* color) {
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (color[neighbor] == -1) {
            // Assign opposite color
            color[neighbor] = 1 - color[node];
            if (!dfs(graph, graphColSize, neighbor, color)) return false;
        } else if (color[neighbor] == color[node]) {
            // Same color conflict
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1; // uncolored
    }

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            color[i] = 0; // start coloring
            if (!dfs(graph, graphColSize, i, color)) {
                free(color);
                return false;
            }
        }
    }

    free(color);
    return true;
}
