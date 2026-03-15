typedef struct {
    int val;
    int freq;
} Pair;

// Swap helper
void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(Pair heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].freq > heap[index].freq) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(Pair heap[], int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;
        if (right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Count frequencies using hash map
    // For simplicity, use a map with dynamic array (value range may vary)
    // We'll use qsort later to manage unique values

    // First, collect unique values and frequencies
    int *unique = (int*)malloc(sizeof(int) * numsSize);
    int *freq = (int*)malloc(sizeof(int) * numsSize);
    int uniqueCount = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (unique[j] == nums[i]) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            unique[uniqueCount] = nums[i];
            freq[uniqueCount] = 1;
            uniqueCount++;
        } else {
            freq[found]++;
        }
    }

    // Step 2: Use min-heap of size k
    Pair *heap = (Pair*)malloc(sizeof(Pair) * k);
    int heapSize = 0;

    for (int i = 0; i < uniqueCount; i++) {
        Pair p;
        p.val = unique[i];
        p.freq = freq[i];

        if (heapSize < k) {
            heap[heapSize] = p;
            heapifyUp(heap, heapSize);
            heapSize++;
        } else {
            if (p.freq > heap[0].freq) {
                heap[0] = p;
                heapifyDown(heap, heapSize, 0);
            }
        }
    }

    // Step 3: Extract results
    int *result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < heapSize; i++) {
        result[i] = heap[i].val;
    }

    *returnSize = heapSize;

    free(unique);
    free(freq);
    free(heap);

    return result;
}