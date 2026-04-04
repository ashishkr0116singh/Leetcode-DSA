/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int** rooms, int* roomsColSize, int roomIndex, int* visited) {
    visited[roomIndex] = 1;
    for (int i = 0; i < roomsColSize[roomIndex]; i++) {
        int nextRoom = rooms[roomIndex][i];
        if (!visited[nextRoom]) {
            dfs(rooms, roomsColSize, nextRoom, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* visited = (int*)calloc(roomsSize, sizeof(int));
    dfs(rooms, roomsColSize, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}
