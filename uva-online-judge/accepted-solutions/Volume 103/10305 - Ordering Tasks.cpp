//*****************
// LAM PHAN VIET **
// UVA 10305 - Ordering Tasks
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
#define maxN 101
int n, Number[maxN], Count;
bool cnt[maxN][maxN];

void Visit(int u) {
    For (v, 1, n)
        if (!Number[v] && cnt[u][v])
            Visit(v);
    Number[u] = Count--;
}

main() {
//    freopen("305.inp", "r", stdin); freopen("305.out", "w", stdout);
    int m, u, v;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        memset(Number, 0, sizeof(Number));
        memset(cnt, false, sizeof(cnt));
        while (m--) {
            scanf("%d %d", &u, &v);
            cnt[u][v] = true;
        }
        Count = n;
        For (i, 1, n)
            if (!Number[i]) Visit(i);
        int ans[n+1];
        For (i, 1, n) ans[Number[i]] = i;
        printf("%d", ans[1]);
        For (i, 2, n) printf(" %d", ans[i]);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
