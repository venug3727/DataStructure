#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreOfParentheses(char *s) {
    int score = 0;
    int *stack = (int *)malloc(strlen(s) * sizeof(int));
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[++top] = score;
            score = 0;
        } else {
            score = stack[top--] + (score == 0 ? 1 : 2 * score);
        }
    }

    free(stack);
    return score;
}

int main() {
    char s1[] = "()";
    char s2[] = "(())";
    char s3[] = "()()";

    printf("Input: %s, Output: %d\n", s1, scoreOfParentheses(s1));
    printf("Input: %s, Output: %d\n", s2, scoreOfParentheses(s2));
    printf("Input: %s, Output: %d\n", s3, scoreOfParentheses(s3));

    return 0;
}
