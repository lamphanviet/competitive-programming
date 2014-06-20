//*****************
// LAM PHAN VIET **
// UVA 610 - Street Directions
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <stack>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
int n, Low[maxN], Number[maxN], Part[maxN], Count, nPart;
bool cnt[maxN][maxN];
stack<int> Q;

void Visit(int u) {
    Q.push(u);
    Number[u] = Low[u] = ++Count;
    For (v, 1, n)
        if (cnt[u][v]) {
            cnt[v][u] = false;
            if (Number[v]) Low[u] = min(Low[u], Number[v]);
            else {
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
        }
    int v;
    if (Low[u]==Number[u]) {
        nPart++;
        do {
            v = Q.top(); Q.pop();
            Part[v] = nPart;
        } while (v!=u);
    }
}

main() {
//    freopen("610.inp", "r", stdin); freopen("610.out", "w", stdout);
    int Case = 0, m, u, v;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        For (i, 1, n) {
            For (j, i+1, n)
                cnt[i][j] = cnt[j][i] = false;
            cnt[i][i] = true;
            Number[i] = 0;
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            cnt[u][v] = cnt[v][u] = true;
        }
        Count = nPart = 0; Q = stack<int>();
        For (i, 1, n)
            if (Number[i]==0) {
                Visit(i);
            }
        printf("%d\n\n", ++Case);
        For (i, 1, n)
            For (j, 1, n)
                if (cnt[i][j]) {
                    printf("%d %d\n", i, j);
                    if (Part[i]!=Part[j]) printf("%d %d\n", j, i);
                }
        puts("#");
    }
}

/* lamphanviet@gmail.com - 2011 */
