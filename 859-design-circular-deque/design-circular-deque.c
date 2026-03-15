typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

// Initialize deque
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

// Insert at front
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false; // full
    if (obj->size == 0) {
        obj->front = obj->rear = 0;
    } else {
        obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    }
    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}

// Insert at rear
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false; // full
    if (obj->size == 0) {
        obj->front = obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }
    obj->arr[obj->rear] = value;
    obj->size++;
    return true;
}

// Delete from front
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false; // empty
    if (obj->size == 1) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    obj->size--;
    return true;
}

// Delete from rear
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false; // empty
    if (obj->size == 1) {
        obj->front = obj->rear = -1;
    } else {
        obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    }
    obj->size--;
    return true;
}

// Get front element
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->front];
}

// Get rear element
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->rear];
}

// Check if empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Check if full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Free memory
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}