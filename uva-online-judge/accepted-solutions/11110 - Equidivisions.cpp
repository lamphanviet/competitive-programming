//*****************
// LAM PHAN VIET **
// UVA 11110 - Equidivisions
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 101
const int change[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int n, a[maxN][maxN];

bool isOK(int x, int y) {
    return (x>0 && x<=n && y>0 && y<=n);
}

int DFS(int x, int y, int val) {
    if (!isOK(x, y) || a[x][y]!=val) return 0;
    int u, v, Count = 1;
    a[x][y] = n+1;
    for (int i=0; i<4; i++) {
        u = x+change[i][0]; v = y+change[i][1];
        Count += DFS(u, v, val);
    }
    return Count;
}

main() {
 //   freopen("110.inp", "r", stdin); freopen("110.out", "w", stdout);
    char s[10000];
    while (scanf("%d", &n) && n) {
        For (i, 1, n)
            For (j, i, n)
                a[i][j] = a[j][i] = 1;
        getchar();
        For (i, 2, n) {
            gets(s);
            int len = strlen(s), k = 0, x, y;
            while (k<len) {
                while (k<len && s[k]==' ') k++;
                if (k<len) sscanf(s+k, "%d", &x);
                while (k<len && s[k]!=' ') k++;
                while (k<len && s[k]==' ') k++;
                if (k<len) {
                    sscanf(s+k, "%d", &y);
   //                 printf("%d %d | ", x, y);
                    a[x][y] = i;
                    while (k<len && s[k]!=' ') k++;
                }
            }
        }
        bool f = true;
        for (int i=1; i<=n && f; i++)
            for (int j=1; j<=n && f; j++)
                if (a[i][j]<=n) {
                    int k = DFS(i, j, a[i][j]);
                    if (k!=n) f = false;
                }
        if (f) puts("good");
        else puts("wrong");
    }
}

/* lamphanviet@gmail.com - 2011 */
