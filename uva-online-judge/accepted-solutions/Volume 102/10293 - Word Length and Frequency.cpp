//*****************
// LAM PHAN VIET **
// UVA 10293 - Word Length and Frequency
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100
int n, num[maxN], len;
char line[maxN];

bool isNotAlpha(char ch) {
    return (ch=='.' || ch=='!' || ch==',' || ch==' ' || ch=='?');
}

void Count() {
    int n = strlen(line);
    for (int i=0; i<n; i++)
        if (isalpha(line[i])) len++;
        else if (isNotAlpha(line[i])) {
            num[len]++;
            len = 0;
        }
    if (line[n-1]!='-') {
        num[len]++;
        len = 0;
    }
}

main() {
//    freopen("293.inp", "r", stdin); freopen("293.out", "w", stdout);
    For (i, 0, maxN-1) num[i] = 0;
    len = 0;
    while (gets(line)) {
        if (line[0]!='#') {
            Count();
            continue;
        }
        For (i, 1, maxN-1) {
            if (num[i]) printf("%d %d\n", i, num[i]);
            num[i] = 0;
        }
        len = 0;
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
