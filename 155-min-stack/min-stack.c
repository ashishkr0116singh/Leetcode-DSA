#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000  // maximum stack size

// Define stack structure
typedef struct {
    int arr[MAX];      // main stack
    int minArr[MAX];   // stack to track minimums
    int top;           // index for main stack
    int minTop;        // index for min stack
} MinStack;

// Initialize stack
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

// Push element
void minStackPush(MinStack* obj, int val) {
    if (obj->top == MAX - 1) return; // overflow check
    obj->arr[++obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minArr[obj->minTop]) {
        obj->minArr[++obj->minTop] = val;
    }
}

// Pop element
void minStackPop(MinStack* obj) {
    if (obj->top == -1) return; // underflow check
    int removed = obj->arr[obj->top--];
    if (removed == obj->minArr[obj->minTop]) {
        obj->minTop--;
    }
}

// Get top element
int minStackTop(MinStack* obj) {
    if (obj->top == -1) return INT_MIN; // empty stack
    return obj->arr[obj->top];
}

// Get minimum element
int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return INT_MIN; // empty stack
    return obj->minArr[obj->minTop];
}

// Free memory
void minStackFree(MinStack* obj) {
    free(obj);
}