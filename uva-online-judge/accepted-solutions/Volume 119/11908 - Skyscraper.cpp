// 11908 - Skyscraper
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

#define maxN 30000+5
typedef struct Ad {
    int s, f, w;
};
int n;
Ad a[maxN];
vector <Ad> b;

bool cmp(Ad a, Ad b) {
    return (a.f<b.f);
}

void Enter() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d %d %d", &a[i].s, &a[i].f, &a[i].w);
        a[i].f = a[i].f+a[i].s-1;
    }
}

void Solve() {
    b.clear();
    int u, v;
    Ad k;
    sort(a+1, a+n+1, cmp);
    b.push_back(a[1]);
    for (int i=2; i<=n; i++) {
        k = a[i];
        if (k.s>b.back().f) {
            k.w += b.back().w;
            b.push_back(k);
            continue;
        }
        
        for (u=0, v=b.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (b[mid].f<k.s) u = mid+1;
            else v = mid;
        }
        
        if (u>0) {
            u--;
            k.w += b[u].w;
        }
        if (k.w>b.back().w) b.push_back(k);
    }
}

main() {
//    freopen("jj.inp", "r", stdin); freopen("jj.out", "w", stdout);
    int kase;
    scanf("%d", &kase);
    for (int kk=1; kk<=kase; kk++) {
        Enter();
        Solve();
        printf("Case %d: %d\n", kk, b.back().w);
    }
}
