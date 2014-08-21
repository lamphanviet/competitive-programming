//*****************
// LAM PHAN VIET **
// UVA 615 - Is It A Tree
// Time limit:
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
int n;
vector<int> Lab;
map<int, int> Index;

int GetRoot(int v) {
    if (Lab[v]<0) return v;
    Lab[v] = GetRoot(Lab[v]);
    return Lab[v];
}

void Union(int r1, int r2) {
    Lab[r1] += Lab[r2];
    Lab[r2] = r1;
}

int GetIndex(int u) {
    int idx = Index[u];
    if (idx!=0) return idx;
    idx = Index[u] = ++n;
    Lab.push_back(-1);
    return idx;
}

main() {
//    freopen("615.inp", "r", stdin); freopen("615.out", "w", stdout);
    int Case = 0, u, v;
    while (scanf("%d %d", &u, &v)!=EOF) {
        if (u<0 && v<0) break;
        Lab.clear(); Lab.push_back(0);
        Index.clear();
        n = 0;
        bool isTree = true;
        while (u || v) {
            if (isTree) {
                u = GetIndex(u); v = GetIndex(v);
                if (Lab[v]>0) isTree = false;
                else {
                    u = GetRoot(u);
                    if (u==v) isTree = false;
                    else Union(u, v);
                }
            }
            scanf("%d %d", &u, &v);
        }
        bool oneRoot = false;
        for (int i=1; i<=n && isTree; i++)
            if (Lab[i]<0) {
                oneRoot = !oneRoot;
                if (!oneRoot) isTree = false;
            }
        printf("Case %d is ", ++Case);
        if (isTree) puts("a tree.");
        else puts("not a tree.");
    }
}

/* lamphanviet@gmail.com - 2011 */
