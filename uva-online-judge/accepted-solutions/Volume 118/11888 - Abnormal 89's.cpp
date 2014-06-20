// 11888 - Abnormal 89's
#include <stdio.h>
#include <string.h>

#define N 200000

char str[N+5];
int n;

int Check() {
    n = strlen(str); n--;
    if (n<=0) return 2;
    int mid, i, j;
    for (mid=1; mid<=n; mid++) {
        i=0; j=mid-1;
        while (i<j && str[i]==str[j]) {
            i++; j--;
        }
        if (i>=j) {
            i=mid; j=n;
            while (i<j && str[i]==str[j]) {
                i++; j--;
            }
        }
        if (i>=j) return 1;
    }
    for (i=0, j=n; i<=j; i++, j--)
        if (str[i]!=str[j]) return 3;
    return 2;
}

int main() {
    int kase;
    scanf("%d", &kase); getchar();
    while (kase--) {
        gets(str);
        int ans = Check();
        switch (ans) {
            case 1: printf("alindrome\n"); break;
            case 2: printf("palindrome\n"); break;
            case 3: printf("simple\n");
        }
    }
    return 0;
}
