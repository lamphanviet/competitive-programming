//*****************
// LAM PHAN VIET **
// UVA 10842 - Traffic Flow
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
#define INF 500000000
#define maxN 101
class Road {
public:
    int u, v, cost;
    Road() { u=v=cost=0; }
    Road(int a, int b, int w) {
        u = a; v = b; cost = w;
    }
};
int n, c[maxN], Lab[maxN];
vector<Road> road;

bool cmp(Road a, Road b) {
    return (a.cost > b.cost);
}

int GetRoot(int v) {
    if (Lab[v]>=0) v = GetRoot(Lab[v]);
    return v;
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

int Kruskal() {
    sort(road.begin(), road.end(), cmp);
    int ans = INF, r1, r2, Count=0;
    for (int k=0, size=road.size(); k<size; k++) {
        r1 = GetRoot(road[k].u);
        r2 = GetRoot(road[k].v);
        if (r1!=r2) {
            Union(r1, r2);
            ans = road[k].cost;
            if (++Count==n-1) break;
        }
    }
    if (ans==INF) {
        ans = 0;
        For (i, 0, n-1) ans = max(ans, c[i]);
    }
    return ans;
}

main() {
 //   freopen("842.inp", "r", stdin); freopen("842.out", "w", stdout);
    int Case, m, u, v, cost;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        scanf("%d %d", &n, &m);
        For (i, 0, n-1) {
            Lab[i] = -1;
            c[i] = 0;
        }
        road.clear();
        while (m--) {
            scanf("%d %d %d", &u, &v, &cost);
            if (u==v) c[u] = max(c[u], cost);
            else road.push_back(Road(u, v, cost));
        }
        printf("Case #%d: %d\n", kk, Kruskal());
    }
}

/* lamphanviet@gmail.com - 2011 */
