//*****************
// LAM PHAN VIET **
// UVA 11235 - Frequent values
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
#define maxN 100001
int n, a[maxN], U, V, ans, q;
int F[maxN*3];
int Left[maxN*3], Right[maxN*3];

void Update(int pos, int L, int R) {
    if (L==R) {
        F[pos] = 1;
        Left[pos] = Right[pos] = 1;
        return;
    }
    int mid = (L+R)/2, c = pos+pos;
    Update(c, L, mid);
    Update(c+1, mid+1, R);
    F[pos] = max(F[c], F[c+1]);
    if (a[mid]==a[mid+1])
        F[pos] = max(F[pos], Right[c] + Left[c+1]);
    Left[pos] = Left[c];
    if (a[L]==a[mid+1]) Left[pos] += Left[c+1];
    Right[pos] = Right[c+1];
    if (a[R]==a[mid]) Right[pos] += Right[c];
}

void Get(int pos, int L, int R) {
    if (V<L || R<U) return;
    if (U<=L && R<=V) {
        ans = max(ans, F[pos]);
        return;
    }
    
    int mid = (L+R)/2, c = pos+pos;
    Get(c, L, mid);
    Get(c+1, mid+1, R);
    if (a[mid]==a[mid+1]) {
        int x = Right[c], y = Left[c+1];
        x = min(x, mid-U+1);
        y = min(y, V-mid);
        ans = max(ans, x+y);
    }
}

main() {
//    freopen("235.inp", "r", stdin); freopen("235.out", "w", stdout);
    while (scanf("%d", &n) && n) {
        scanf("%d", &q);
        For (i, 1, n) scanf("%d", &a[i]);
        Update(1, 1, n);
        while (q--) {
            ans = 0;
            scanf("%d %d", &U, &V);
            Get(1, 1, n);
            printf("%d\n", ans);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
