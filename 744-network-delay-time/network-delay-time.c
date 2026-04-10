/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    // Build adjacency matrix (n+1 for 1-based indexing)
    int** graph = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int*)malloc((n+1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            graph[i][j] = -1; // -1 means no edge
        }
    }

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    // Dijkstra’s algorithm
    int* dist = (int*)malloc((n+1) * sizeof(int));
    bool* visited = (bool*)malloc((n+1) * sizeof(bool));
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[k] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int minDist = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != -1 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            // Free memory
            for (int j = 0; j <= n; j++) free(graph[j]);
            free(graph);
            free(dist);
            free(visited);
            return -1; // unreachable node
        }
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    // Free memory
    for (int j = 0; j <= n; j++) free(graph[j]);
    free(graph);
    free(dist);
    free(visited);

    return maxTime;
}
