//*****************
// LAM PHAN VIET **
// UVA 11503 - Virtual Friends
// Time limit: 10.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
map<string, int> Index;
vector<int> Lab;

int GetRoot(int v) {
    if (Lab[v]<0) return v;
    else {
        Lab[v] = GetRoot(Lab[v]);
        return Lab[v];
    }
}

int  Union(int r1, int r2) {
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1]>Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
    return -x;
}

main() {
//    freopen("503.inp", "r", stdin); freopen("503.out", "w", stdout);
    int Case, m, Count, u, v;
    char name1[22], name2[22];
    scanf("%d", &Case);
    while (Case--) {
        Count = 0;
        Index.clear(); Lab.clear(); Lab.push_back(0);
        scanf("%d", &m); getchar();
        while (m--) {
            scanf("%s %s", &name1, &name2);
            u = Index[name1];
            if (u==0) {
                u = Index[name1] = ++Count;
                Lab.push_back(-1);
            }
            v = Index[name2];
            if (v==0) {
                v = Index[name2] = ++Count;
                Lab.push_back(-1);
            }
            u = GetRoot(u); v = GetRoot(v);
            if (u==v) printf("%d\n", -Lab[u]);
            else printf("%d\n", Union(u, v));
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
