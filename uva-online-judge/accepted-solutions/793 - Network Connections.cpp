//*****************
// LAM PHAN VIET **
// UVA 793 - Network Connections
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
int n;
vector<int> Lab;

int GetRoot(int v) {
//    if (Lab[v]>0)  v = GetRoot(Lab[v]);
    if (Lab[v]<0) return v;
    Lab[v] = GetRoot(Lab[v]);
    return Lab[v];
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
//    freopen("793.inp", "r", stdin); freopen("793.out", "w", stdout);
    int Case, scs, unscs, u, v;
    char s[30], form;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n); getchar();
        Lab = vector<int>(n+1, -1);
        scs = unscs = 0;
        while (gets(s) && strlen(s)) {
            sscanf(s, "%c %d %d", &form, &u, &v);
 //           printf("%c %d %d\n", form, u, v);
            u = GetRoot(u); v = GetRoot(v);
 //           printf("%d %d\n", u, v);
            if (form=='q') {
                if (u==v) scs++;
                else unscs++;
            }
            else if (u!=v) Union(u, v);
        }
        printf("%d,%d\n", scs, unscs);
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
