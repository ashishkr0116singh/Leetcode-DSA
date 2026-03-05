// LeetCode Problem 150: Evaluate Reverse Polish Notation
// Language: C

int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];   // stack to hold operands
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        // Check if token is an operator
        if (strcmp(t, "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        } else if (strcmp(t, "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        } else if (strcmp(t, "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        } else if (strcmp(t, "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;   // integer division
        } else {
            // Operand: convert string to integer
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}