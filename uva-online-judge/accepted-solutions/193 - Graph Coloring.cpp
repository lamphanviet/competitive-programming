//----------------------------
// LAM PHAN VIET
// UVA 193 - Graph Coloring
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 102
int color[maxN], n;
vector<int> adj[maxN];
vector<int> ans;

void Backtracking(int u, vector<int> tmp) {
    vector<int> save;
    color[u] = -1; tmp.push_back(u);
  //  printf("%d \n", u);
    for (int j=0, sizeu=adj[u].size(); j<sizeu; j++) {
        int v = adj[u][j];
        if (color[v]==0) {
            color[v] = 1;
            save.push_back(v);
        }
    }
    bool found = false;
    for (int v=u+1; v<=n; v++)
        if (color[v]==0) {
            Backtracking(v, tmp);
            found = true;
            break;
        }
    if (!found && ans.size()<tmp.size()) ans = tmp;

    for (int j=0, sizes=save.size(); j<sizes; j++)
        color[save[j]] = 0;
    color[u] = 1; tmp.pop_back();
    for (int v=u+1; v<=n; v++)
        if (color[v]==0) {
            Backtracking(v, tmp);
            break;
        }
    color[u] = 0;
}

main() {
 //   freopen("193.inp", "r", stdin); freopen("193.out", "w", stdout);
    int Case, m, u, v;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; i++) {
            adj[i].clear(); color[i] = 0;
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v); adj[v].push_back(u);
        }
        ans.clear();
        Backtracking(1, ans);
        printf("%d\n", ans.size());
        if (ans.size()>0) printf("%d", ans[0]);
        for (int i=1, sizea=ans.size(); i<sizea; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
}
