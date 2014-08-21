// 483 - Word Scramble
#include <iostream>

using namespace std;

char s[1000];

void Order(int a, int b) {
    int mid = (a+b)/2;
    char temp;
    for (int i=a;i<=mid;i++) {
        temp = s[i]; s[i] = s[a+b-i]; s[a+b-i] = temp;
    }
}

main() {
    int n,k,i;
    while (gets(s)) {
        n =strlen(s);
        k = 0;
        while (k<n) {
            while (k<n && s[k]==' ') k++;
            if (k==n) break;
            i = k+1;
            while (i<n && s[i]!=' ') i++;
            Order(k,i-1);
            k = i;
        }
        puts(s);
    }
}
