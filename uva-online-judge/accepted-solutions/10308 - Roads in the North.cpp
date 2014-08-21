//*****************
// LAM PHAN VIET **
// UVA 10308 - Roads in the North
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10001
int n, ans;
vector<int> adj[maxN];
vector<int> adjw[maxN];
bool Free[maxN];

int DFS(int u, int val) {
    int tmpmax = 0, tmp;
    bool leaf = true;
    for (int i=0, size=adj[u].size(); i<size; i++) {
        int v = adj[u][i];
        if (!Free[v]) continue;
        Free[v] = false;
        tmp = DFS(v, adjw[u][i]);
        ans = max(ans, tmpmax+tmp);
        tmpmax = max(tmpmax, tmp);
        leaf = false;
    }
    return tmpmax+val;
}

main() {
 //   freopen("308.inp", "r", stdin); freopen("308.out", "w", stdout);
    int u, v, w;
    char s[30];
    while (gets(s)) {
        For (i, 0, maxN-1) {
            Free[i] = true;
            adj[i].clear(); adjw[i].clear();
        }
        n = 0;
        do {
            if (strlen(s)==0) break;
            sscanf(s, "%d %d %d", &u, &v, &w);
            adj[u].push_back(v); adjw[u].push_back(w);
            adj[v].push_back(u); adjw[v].push_back(w);
            n = max(n, u); n = max(n, v);
        } while (gets(s));
        ans = 0;
        Free[1] = false;
        DFS(1, 0);
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
