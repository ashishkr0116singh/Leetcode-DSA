// LeetCode Problem 227: Basic Calculator II
// Language: C

int calculate(char* s) {
    int n = strlen(s);
    long stack[n];   // stack to hold numbers
    int top = -1;
    long num = 0;
    char sign = '+'; // previous operator

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // build number
        }

        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            if (sign == '+') {
                stack[++top] = num;
            } else if (sign == '-') {
                stack[++top] = -num;
            } else if (sign == '*') {
                stack[top] = stack[top] * num;
            } else if (sign == '/') {
                stack[top] = stack[top] / num;
            }
            sign = c;
            num = 0;
        }
    }

    long result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return (int)result;
}