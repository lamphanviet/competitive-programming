//*****************
// LAM PHAN VIET **
// UVA 869 - Airline Comparison
// Time limit:
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100
int m1, m2;
bool cnt[2][maxN][maxN];

bool Check() {
    For (i, 'A', 'Z')
        For (j, 'A', 'Z')
            if (cnt[0][i][j]!=cnt[1][i][j]) return false;
    return true;
}

void Process(int k) {
    int m;
    char c1, c2;
    scanf("%d", &m);
    while (m--) {
        scanf(" %c %c ", &c1, &c2);
        c1 = toupper(c1); c2 = toupper(c2);
        cnt[k][c1][c2] = cnt[k][c2][c1] = true;
    }
    For (t, 'A', 'Z')
        For (u, 'A', 'Z')
            For (v, 'A', 'Z')
                cnt[k][u][v] = cnt[k][u][v] || (cnt[k][u][t] && cnt[k][t][v]);
}

main() {
//    freopen("869.inp", "r", stdin); freopen("869.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        For (i, 'A', 'Z')
            For (j, 'A', 'Z')
                cnt[0][i][j] = cnt[1][i][j] = false;
        Process(0);
        Process(1);
        bool ans = Check();
        if (ans) puts("YES");
        else puts("NO");
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
