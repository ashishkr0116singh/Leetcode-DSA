void dfs(int** isConnected, int isConnectedSize, int* visited, int city) {
    visited[city] = 1;
    for (int j = 0; j < isConnectedSize; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(isConnected, isConnectedSize, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(isConnected, isConnectedSize, visited, i);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}
