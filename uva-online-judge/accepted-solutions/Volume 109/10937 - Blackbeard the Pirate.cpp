//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10937 - Blackbeard the Pirate
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 55

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const int dxx[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
const int dyy[] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int n, m, nt, sx, sy, dist[maxN][maxN], d[11][11];
char s[maxN][maxN];
vii tre;
int f[10][BIT(10)];

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

bool valid(int x, int y) {
    if (!inside(x, y)) return false;
    if (s[x][y] == '#' || s[x][y] == '~' || s[x][y] == '*') return false;
    if (dist[x][y] != INF) return false;
    rep(i, 8) {
        int xx = x + dxx[i], yy = y + dyy[i];
        if (inside(xx, yy) && s[xx][yy] == '*') return false;
    }
    return true;
}

void bfs(int x, int y, int it) {
    rep(i, n) rep(j, m) dist[i][j] = INF;
    rep(i, nt + 1) d[it][i] = INF; d[it][it] = 0;
    queue<ii> q;
    q.push(mp(x, y)); dist[x][y] = 0;
    while (!q.empty()) {
        ii top = q.front(); q.pop();
        x = top.ff, y = top.ss;
        rep(i, 4) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!valid(xx, yy)) continue;
            dist[xx][yy] = dist[x][y] + 1;
            if (0 <= s[xx][yy] && s[xx][yy] < nt)
                d[s[xx][yy]][it] = d[it][s[xx][yy]] = dist[xx][yy];
            q.push(mp(xx, yy));
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    while (scanf(" %d %d ", &n, &m) && (n | m)) {
        nt = 0;
        tre.clear();
        rep(i, n) {
            scanf(" %s ", s[i]);
            rep(j, m)
                if (s[i][j] == '!') {
                    s[i][j] = nt++;
                    tre.pb(mp(i, j));
                }
                else if (s[i][j] == '@')
                    sx = i, sy = j;
        }
        dist[sx][sy] = INF;
        if (!valid(sx, sy)) {
            puts("-1");
            continue;
        }
        rep(i, nt) bfs(tre[i].ff, tre[i].ss, i);
        bfs(sx, sy, nt);
        int k = BIT(nt);
        rep(i, nt) rep(j, k) f[i][j] = INF;
        rep(i, nt) f[i][BIT(i)] = d[nt][i];
        rep(j, k) rep(i, nt) if (f[i][j] != INF) {
            rep(t, nt) if (!(j & BIT(t)))
                f[t][j | BIT(t)] = min(f[t][j | BIT(t)], f[i][j] + d[i][t]);
        }
        int res = INF;
        rep(i, nt) res = min(res, f[i][k - 1] + d[nt][i]);
        if (nt == 0) res = 0;
        if (res == INF) res = -1;
        printf("%d\n", res);
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
