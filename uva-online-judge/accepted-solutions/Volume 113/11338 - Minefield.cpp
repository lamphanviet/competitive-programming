//============================
// Author: lamphanviet@gmail.com
// Problem: 11338 - Minefield
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
#include <cmath>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a); i <= (b); i++)
#define frr(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define int64 long long
#define uint64 unsigned long long
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

#define INF 10001112221111111.0
#define maxN 10011
#define eps 1e-7

int n, st, nd, w, h;
double dist, x[maxN], y[maxN];
double d[maxN];

double cnt(int i, int j) {
    double xx = x[i] - x[j];
    double yy = y[i] - y[j];
    return sqrt(xx * xx + yy * yy);
}

bool dijkstra() {
    set< pair<double, int> > heap;
    fr(i, 0, nd) d[i] = INF;
    d[st] = 0.0;
    heap.insert(mp(d[st], st));
    while (!heap.empty()) {
        pair<double, int> top = *heap.begin();
        heap.erase(top);
        int u = top.second;
        if (u == nd) break;
        fr(v, 0, nd) {
            double dd = cnt(u, v);
            if (dd <= 1.5 && dd + d[u] < d[v]) {
                heap.erase(mp(d[v], v));
                d[v] = d[u] + dd;
                heap.insert(mp(d[v], v));
            }
        }
    }
    return d[nd] <= dist;
}
char s[100];

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    
    while (scanf(" %s ", &s) != EOF) {
        if (s[0] == '*') break;
        sscanf(s, " %d ", &w);
        scanf(" %d ", &h);
        scanf(" %d ", &n);
        fr(i, 1, n) scanf(" %lf %lf ", &x[i], &y[i]);
        scanf(" %lf ", &dist);
        st = 0, nd = n + 1;
        x[0] = y[0] = 0.0;
        x[nd] = w; y[nd] = h;
        if (dijkstra()) puts("I am lucky!");
        else puts("Boom!");
    }
    return 0;
}
