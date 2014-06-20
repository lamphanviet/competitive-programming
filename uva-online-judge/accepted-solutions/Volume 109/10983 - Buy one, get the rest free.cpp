//============================
// Author: lamphanviet@gmail.com
// Problem: 10983 - Buy one, get the rest free
//============================
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <cmath>

using namespace std;

#define fr(i,a,b) for (int i = (a); i <= (b); i++)
#define frr(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define int64 long long
#define uint64 unsigned long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

#define INF 1000111222
#define maxN 1011

int n, d, m, st, nd;
int x[maxN], y[maxN], pas[maxN], c[maxN], e[maxN];
int f, fnet[350][350], parent[350];
int numbers[50], sum;
vi adj[350];

int pos[33][11];

int getPos(int city, int startDay) {
    return pos[city][startDay];
}

int augment(int v, int minEdge) {
    if (v == st) f = minEdge;
    else if (parent[v] != -1) {
        int u = parent[v];
        augment(u, min(minEdge, fnet[u][v]));
        fnet[u][v] -= f; fnet[v][u] += f;
    }
}

bool accept(int limitCost) {
    // build graph
    rep(i, 350) adj[i].clear();
    fill(fnet, 0);
    rep(i, m) if (c[i] <= limitCost) {
        int u = getPos(x[i], e[i]);
        int v = getPos(y[i], e[i] + 1);
        fnet[u][v] += pas[i];
        adj[u].pb(v); adj[v].pb(u);
        //printf("add1 %d %d: %d\n", u, v, pas[i]);
    }
    fr(i, 1, n) {
        rep(j, d) {
            int u = getPos(i, j);
            int v = getPos(i, j + 1);
            adj[u].pb(v); adj[v].pb(u);
            fnet[u][v] = INF;
          //  printf("add2 %d %d: %d\n", u, v, INF);
        }
    }
    fr(i, 1, n) {
        int v = getPos(i, 0);
        adj[st].pb(v); adj[v].pb(st);
        fnet[st][v] = numbers[i];
      //  printf("add3 %d %d: %d\n", st, v, numbers[i]);
    }
    // find flow
    int mf = 0;
    do {
        f = 0;
        fill(parent, -1);
        queue<int> q;
        q.push(st); parent[st] = st;
        while (!q.empty()) {
            int u = q.front(); q.pop();
       //     printf("u %d\n", u);
            if (u == nd) break;
            rep(i, adj[u].size()) {
                int v = adj[u][i];
                if (fnet[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
     //   printf("f %d\n", f);
        augment(nd, INF);
        mf += f;
    } while (f);
  //  printf("mf %d\n", mf);
    return (mf == sum);
  //  return false;
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int tmpNumber = 0;
    fr(i, 0, 30) fr(j, 0, 10) {
        pos[i][j] = ++tmpNumber;
    }
    //printf("tmp %d\n", tmpNumber);
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        set<int> setCost;
        scanf("%d %d %d", &n, &d, &m);
        rep(i, m) {
            scanf("%d %d %d %d %d", &x[i], &y[i], &pas[i], &c[i], &e[i]);
            setCost.insert(c[i]);
        }
        sum = 0;
        fr(i, 1, n) {
            scanf("%d", &numbers[i]);
            sum += numbers[i];
        }
        
        vi allCost;
        for (set<int>::iterator it = setCost.begin(); it != setCost.end(); it++) {
            allCost.pb(*it);
        }
//        rep(i, allCost.size()) printf("%d ", allCost[i]); puts("");
        st = getPos(0, 0);
        nd = getPos(n, d);
        //printf("st %d %d\n", st, nd);
        int lo = 0, hi = allCost.size() - 1, res = INF;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (accept(allCost[mid])) {
                res = min(res, allCost[mid]);
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        printf("Case #%d: ", ++caseNo);
        if (res == INF) puts("Impossible");
        else printf("%d\n", res);
    }
    return 0;
}
