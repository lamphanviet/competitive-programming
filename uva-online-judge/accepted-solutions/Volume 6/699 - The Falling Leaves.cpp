//*****************
// LAM PHAN VIET **
// UVA 699 - The Falling Leaves
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 101
#define Mid maxN/2
int Min, Max, ans[maxN];

void ReadTree(int p) {
    int val;
    scanf("%d", &val);
    if (val==-1) return;
    ans[p] += val;
    Min = min(Min, p);
    Max = max(Max, p);
    ReadTree(p-1);
    ReadTree(p+1);
}

main() {
//    freopen("699.inp", "r", stdin); freopen("699.out", "w", stdout);
    int Case = 0, val;
    while (scanf("%d", &val) && val!=-1) {
        For (i, 0, maxN-1) ans[i] = 0;
        Min = Max = Mid;
        ans[Mid] = val;
        ReadTree(Mid-1);
        ReadTree(Mid+1);
        printf("Case %d:\n", ++Case);
        printf("%d", ans[Min]);
        For (i, Min+1, Max) printf(" %d", ans[i]);
        printf("\n\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
