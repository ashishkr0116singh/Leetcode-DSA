/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;

    // Stack to store indices
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        // Pop indices with temperatures <= current
        while (top >= 0 && temperatures[stack[top]] <= temperatures[i]) {
            top--;
        }

        // If stack empty → no warmer day
        if (top == -1) {
            result[i] = 0;
        } else {
            result[i] = stack[top] - i;
        }

        // Push current index
        stack[++top] = i;
    }

    free(stack);
    return result;
}