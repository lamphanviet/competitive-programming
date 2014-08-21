//*****************
// LAM PHAN VIET **
// UVA 291 - The House Of Santa Claus
// Time limit:  3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 6
#define M 8
#define n 5
bool cnt[maxN][maxN];

void CreateGraph() {
    For (i, 1, n) memset(cnt[i], false, maxN);
    cnt[1][2] = cnt[1][3] = cnt[1][5] = true;
    cnt[2][1] = cnt[2][3] = cnt[2][5] = true;
    cnt[3][1] = cnt[3][2] = cnt[3][4] = cnt[3][5] = true;
    cnt[4][3] = cnt[4][5] = true;
    cnt[5][1] = cnt[5][2] = cnt[5][3] = cnt[5][4] = true;
}

void Backtracking(int u, int m, string ans) {
    if (m==M) {
        cout << ans << endl; return;
    }
    For (v, 1, n)
        if (cnt[u][v]) {
            cnt[u][v] = cnt[v][u] = false;
            string tmp = ans; tmp += (v+48);
            Backtracking(v, m+1, tmp);
            cnt[u][v] = cnt[v][u] = true;
        }
}

main() {
//    freopen("291.inp", "r", stdin); freopen("291.out", "w", stdout);
    CreateGraph();
    Backtracking(1, 0, "1");
//    system("pause");
}

/* lamphanviet@gmail.com - 2011 */
