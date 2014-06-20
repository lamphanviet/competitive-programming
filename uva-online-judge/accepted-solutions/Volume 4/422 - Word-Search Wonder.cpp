//*****************
// LAM PHAN VIET **
// UVA 422 - Word-Search Wonder
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 102
const int x[] = {-1, -1, 0, 1, 1,  1,  0}; // {-1, -1, -1, 0, 1, 1,  1,  0}
const int y[] = {-1,  1, 1, 1, 0, -1, -1}; // {-1,  0,  1, 1, 1, 0, -1, -1}
int n;
char s[maxN][maxN];
char word[maxN];

bool isOK(int i, int j) {
    return (i>=0 && i<n && j>=0 && j<n);
}

bool Find() {
    int len = strlen(word);
    For (i, 0, n-1)
        For (j, 0, n-1)
            if (s[i][j]==word[0]) {
                For (k, 0, 7) {
                    int u = i, v = j, t = 0;
                    while (isOK(u, v) && t<len && s[u][v]==word[t]) {
                        u += x[k]; v += y[k];
                        t++;
                    }
                    if (t==len) {
                        printf("%d,%d %d,%d\n", i+1, j+1, u-x[k]+1, v-y[k]+1);
                        return true;
                    }
                }
            }
    return false;
}

main() {
//    freopen("422.inp", "r", stdin); freopen("422.out", "w", stdout);
    scanf("%d", &n); gets(s[0]);
    For (i, 0, n-1) gets(s[i]);
    while (gets(word)) {
        if (word[0]=='0') break;
        if (!Find()) printf("Not found\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
