/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** graph = (int**)malloc(sizeof(int*) * numCourses);
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(sizeof(int) * prerequisitesSize); // allocate only as needed
        graphColSize[i] = 0;
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
        indegree[course]++;
    }

    // Queue for BFS
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    int* order = (int*)malloc(sizeof(int) * numCourses);
    int idx = 0;

    while (front < rear) {
        int curr = queue[front++];
        order[idx++] = curr;

        for (int i = 0; i < graphColSize[curr]; i++) {
            int next = graph[curr][i];
            indegree[next]--;
            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    // Free memory
    for (int i = 0; i < numCourses; i++) free(graph[i]);
    free(graph);
    free(graphColSize);
    free(indegree);
    free(queue);

    if (idx == numCourses) {
        *returnSize = idx;
        return order; // valid topological order
    } else {
        free(order);
        *returnSize = 0;
        return NULL; // cycle detected
    }
}
