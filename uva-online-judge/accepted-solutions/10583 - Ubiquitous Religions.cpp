//*****************
// LAM PHAN VIET **
// UVA 10583 - Ubiquitous Religions
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
#define maxN 50001
int n, Lab[maxN];

int GetRoot(int v) {
    if (Lab[v]>0) v = GetRoot(Lab[v]);
    return v;
}

void Union(int r1, int r2) {
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1]>Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

main() {
 //   freopen("583.inp", "r", stdin); freopen("583.out", "w", stdout);
    int Case = 0, m, u, v;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        For (i, 1, n) Lab[i] = -1;
        while (m--) {
            scanf("%d %d", &u, &v);
            u = GetRoot(u); v = GetRoot(v);
            if (u!=v) Union(u, v);
        }
        int Count = 0;
        For (i, 1, n) if (Lab[i]<0) Count++;
        printf("Case %d: %d\n", ++Case, Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
