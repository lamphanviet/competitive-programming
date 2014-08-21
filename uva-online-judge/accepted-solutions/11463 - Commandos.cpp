//----------------------------
// LAM PHAN VIET
// UVA 11463 - Commandos
// Time limit: 2s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define maxN 100
#define INF 1000000
int n, ans, s, f;
int d[maxN];
vector<int> ke[maxN];

void BFS() {
    int u = s;
    for (int i=0; i<n; i++) d[i] = INF;
    queue<int> Queue;
    Queue.push(u);
    d[u] = 0;
    while (!Queue.empty()) {
        u = Queue.front();
        Queue.pop();
        for (int i=0, sizeu=ke[u].size(); i<sizeu; i++) {
            int v = ke[u][i];
            if (d[v]!=INF) continue;
            d[v] = d[u]+1;
            Queue.push(v);
        }
    }
}

void BFS2(int u) {
    int d2[n];
    for (int i=0; i<n; i++) d2[i] = 0;
    
    queue<int> Queue;
    Queue.push(u);
    d2[u] = d[u];
    while (!Queue.empty()) {
        u = Queue.front();
        Queue.pop();
        for (int i=0, sizeu=ke[u].size(); i<sizeu; i++) {
            int v = ke[u][i];
            if (d2[v]) continue;
            d2[v] = d2[u]+1;
            if (v==f) {
                ans = max(ans, d2[v]);
                return;
            }
            Queue.push(v);
        }
    }

}

main() {
//    freopen("463.inp", "r", stdin); freopen("463.out", "w", stdout);
    int Case, m, u, v;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<maxN; i++)
            ke[i].clear();
        while (m--) {
            scanf("%d %d", &u, &v);
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        scanf("%d %d", &s, &f);
        BFS();
        ans = d[f];
        for (int i=0; i<n; i++)
            if (i!=s && i!=f) BFS2(i);
        printf("Case %d: %d\n",kk, ans);
    }
}
