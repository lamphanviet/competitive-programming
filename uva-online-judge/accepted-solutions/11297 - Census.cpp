//*****************
// LAM PHAN VIET **
// UVA 11297 - Census
// Time limit: 8.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 1<<30
#define maxN 505
int n, m, a[maxN];
int Max[maxN][maxN*3], Min[maxN][maxN*3];
int ansMax, ansMin, U, V;

void MakeTree(int r, int p, int L, int R) {
    if (L==R) {
        Max[r][p] = Min[r][p] = a[L];
        return;
    }
    int mid = (L+R)/2, c = p+p;
    MakeTree(r, c, L, mid);
    MakeTree(r, c+1, mid+1, R);
    Max[r][p] = max(Max[r][c], Max[r][c+1]);
    Min[r][p] = min(Min[r][c], Min[r][c+1]);
}

void Update(int r, int p, int L, int R, int val) {
    if (V==L && L==R) {
        Max[r][p] = Min[r][p] = val;
        return;
    }
    if (V<L || R<V) return;
    int mid = (L+R)/2, c = p+p;
    Update(r, c, L, mid, val);
    Update(r, c+1, mid+1, R, val);
    Max[r][p] = max(Max[r][c], Max[r][c+1]);
    Min[r][p] = min(Min[r][c], Min[r][c+1]);
}

void Get(int r, int p, int L, int R) {
    if (R<U || V<L) return;
    if (U<=L && R<=V) {
        ansMax = max(ansMax, Max[r][p]);
        ansMin = min(ansMin, Min[r][p]);
        return;
    }
    int mid = (L+R)/2, c = p+p;
    Get(r, c, L, mid);
    Get(r, c+1, mid+1, R);
}

main() {
//    freopen("297.inp", "r", stdin); freopen("297.out", "w", stdout);
    int q, val, r1, r2;
    char ch;
    while (scanf("%d %d", &n, &m)!=EOF) {
        For (i, 1, n) {
            For (j, 1, m)
                scanf("%d", &a[j]);
            MakeTree(i, 1, 1, m);
        }
        scanf("%d", &q);
        while (q--) {
            scanf(" %c ", &ch);
            if (ch=='c') {
                scanf("%d %d %d", &U, &V, &val);
                Update(U, 1, 1, m, val);
            }
            else {
                scanf("%d %d %d %d", &r1, &U, &r2, &V);
                ansMax = -INF; ansMin = INF;
                For (i, r1, r2) Get(i, 1, 1, m);
                printf("%d %d\n", ansMax, ansMin);
            }
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
