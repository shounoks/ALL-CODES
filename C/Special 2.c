#include<stdio.h>
#include<string.h>

int main() {
    char s[30] = "Adhara Paul";
    char s1[30];
    int i, j;
    int len = strlen(s);
    for (j = 0, i = len - 1; i >= 0; i--, j++) {
        s1[j] = s[i];
    }
    s1[j] = '\0';
    printf("The reverse string is : %s\n", s1);

    return 0;
}
