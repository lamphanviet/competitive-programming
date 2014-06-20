//*****************
// LAM PHAN VIET **
// UVA 423 - MPI Maelstrom
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 101

main() {
//    freopen("423.inp", "r", stdin); freopen("423.out", "w", stdout);
    int n, a[maxN][maxN], val;
    char s[10];
    while (scanf("%d", &n)!=EOF) {
        getchar();
        For (i, 2, n)
            For (j, 1, i-1) {
                scanf("%s", &s);
                if (s[0]=='x') a[i][j] = a[j][i] = INF;
                else {
                    sscanf(s, "%d", &val);
                    a[i][j] = a[j][i] = val;
                }
            }
        For (k, 1, n)
            For (u, 1, n)
                For (v, 1, n)
                    a[u][v] = min(a[u][v], a[u][k] + a[k][v]);
        int ans = 0;
        For (i, 1, n) ans = max(ans, a[1][i]);
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
