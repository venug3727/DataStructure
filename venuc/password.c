#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strongPasswordChecker(char *password) {
    int n = strlen(password);
    int res = 0, lower = 1, upper = 1, digit = 1;
    int over_len = n > 20 ? n - 20 : 0;
    int consecutive = 0, delete = 0, insert = 0, replace = 0;
    for (int i = 0; i < n; i++) {
        if (islower(password[i])) lower = 0;
        if (isupper(password[i])) upper = 0;
        if (isdigit(password[i])) digit = 0;
        if (i > 0 && password[i] == password[i - 1]) consecutive++;
        else {
            res += consecutive / 3;
            consecutive = 1;
        }
    }
    res += consecutive / 3;
    res += lower + upper + digit;
    if (n < 6) insert = 6 - n;
    else if (n > 20) {
        delete = over_len;
        replace = over_len;
    }
    return insert + delete + res;
}

int main() {
    char password[51];
    printf("Enter password: ");
    scanf("%s", password);
    int result = strongPasswordChecker(password);
    printf("Minimum number of steps required: %d\n", result);
    return 0;
}
