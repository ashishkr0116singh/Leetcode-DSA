typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

// Create deque
Deque* createDeque(int n) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * n);
    dq->front = 0;
    dq->rear = -1;
    dq->capacity = n;
    return dq;
}

// Check if empty
bool isEmpty(Deque* dq) {
    return dq->rear < dq->front;
}

// Push back
void pushBack(Deque* dq, int val) {
    dq->data[++dq->rear] = val;
}

// Pop back
void popBack(Deque* dq) {
    dq->rear--;
}

// Pop front
void popFront(Deque* dq) {
    dq->front++;
}

// Get front
int getFront(Deque* dq) {
    return dq->data[dq->front];
}

// Get back
int getBack(Deque* dq) {
    return dq->data[dq->rear];
}

// Free deque
void freeDeque(Deque* dq) {
    free(dq->data);
    free(dq);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    Deque* dq = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // Remove indices out of current window
        if (!isEmpty(dq) && getFront(dq) <= i - k) {
            popFront(dq);
        }

        // Remove smaller elements from back
        while (!isEmpty(dq) && nums[getBack(dq)] <= nums[i]) {
            popBack(dq);
        }

        // Add current index
        pushBack(dq, i);

        // Record max for current window
        if (i >= k - 1) {
            result[*returnSize] = nums[getFront(dq)];
            (*returnSize)++;
        }
    }

    freeDeque(dq);
    return result;
}