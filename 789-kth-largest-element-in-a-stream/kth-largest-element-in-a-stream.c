typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[parent] > obj->heap[index]) {
            swap(&obj->heap[parent], &obj->heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;
        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&obj->heap[index], &obj->heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Constructor
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * (numsSize + k + 5));
    obj->size = 0;
    obj->capacity = numsSize + k + 5;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        // add each number
        obj->heap[obj->size++] = nums[i];
        heapifyUp(obj, obj->size - 1);
        if (obj->size > k) {
            // remove smallest
            obj->heap[0] = obj->heap[obj->size - 1];
            obj->size--;
            heapifyDown(obj, 0);
        }
    }
    return obj;
}

// Add new value
int kthLargestAdd(KthLargest* obj, int val) {
    obj->heap[obj->size++] = val;
    heapifyUp(obj, obj->size - 1);
    if (obj->size > obj->k) {
        obj->heap[0] = obj->heap[obj->size - 1];
        obj->size--;
        heapifyDown(obj, 0);
    }
    return obj->heap[0]; // kth largest
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}