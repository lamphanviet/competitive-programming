//----------------------------
// LAM PHAN VIET
// UVA 11492 - Babel
// Time limit: 5s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 2001
#define INF 1000000
class Edge {
public:
    int u, v, cost;
    char first;
    Edge() {
        u = v = cost = 0;
        first = '*';
    }
    Edge(int x, int y, int w, char ch) {
        u = x; v = y; cost = w;
        first = ch;
    }
};
int n, m, s, f;
Edge edge[maxN];
map<string, int> Index;

void Init() {
    Index.clear();
}

void Enter() {
    char s1[55], s2[55], wd[55];
    int u, v;
    getchar();
    scanf("%s %s", &s1, &s2);
    s = f = n = Index[s1] = 1;
    if (strcmp(s1, s2)) f = n = Index[s2] = 2;
    For (k, 1, m) {
        scanf("%s %s %s", &s1, &s2, &wd);
        u = Index[s1];
        if (!u) u = Index[s1] = ++n;
        v = Index[s2];
        if (!v) v = Index[s2] = ++n;
 //       printf("%d %d\n", u, v);
        edge[k] = Edge(u, v, strlen(wd), wd[0]);
    }
}

void Dijkstra() {
    bool Free[m+1][2];
    int d[m+1][2];
    For (i, 1, m) {
        Free[i][0] = Free[i][1] = true;
        if (edge[i].u==s) {
            d[i][0] = 0;
            d[i][1] = edge[i].cost;
        }
        else if (edge[i].v==s) {
            d[i][0] = edge[i].cost;
            d[i][1] = 0;
        }
        else d[i][0] = d[i][1] = INF;
    }
    while (1) {
        int x = 0, k, tmpmin = INF;
        For (i, 1, m) {
            if (Free[i][0] && d[i][0]<tmpmin) {
                x = i; k = 0;
                tmpmin = d[i][0];
            }
            if (Free[i][1] && d[i][1]<tmpmin) {
                x = i; k = 1;
                tmpmin = d[i][1];
            }
        }
        if (x==0) break;
 //       printf("x %d:%d\n", x, k);
        Free[x][k] = false;
        int X = edge[x].u;
        if (k==1) X = edge[x].v;
        For (i, 1, m) {
            int tmpcost = d[x][k] + edge[i].cost;
            if (Free[i][1] && edge[i].u==X) {
                if (edge[i].first!=edge[x].first && tmpcost < d[i][1])
                    d[i][1] = tmpcost;
            }
            if (Free[i][0] && edge[i].v==X) {
                if (edge[i].first!=edge[x].first && tmpcost < d[i][0])
                    d[i][0] = tmpcost;
            }
        }
    }
    int ans = INF;
    For (i, 1, m)
        if (edge[i].u==f) ans = min(d[i][0], ans);
        else if (edge[i].v==f) ans = min(d[i][1], ans);
    if (ans==INF) puts("impossivel");
    else printf("%d\n", ans);
}

main() {
//    freopen("492.inp", "r", stdin); freopen("492.out", "w", stdout);
    while (scanf("%d", &m) && m) {
        Init();
        Enter();
        Dijkstra();
    }
}
