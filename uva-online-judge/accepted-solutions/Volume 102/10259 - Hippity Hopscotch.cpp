//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10259 - Hippity Hopscotch
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
#define maxN 111

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
int n, k, a[maxN][maxN];
int64 f[maxN][maxN];
bool inQueue[maxN][maxN], done[maxN][maxN];

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < n); }

int64 dijkstra() {
    int64 res = a[0][0];
    fill(f, 0); f[0][0] = a[0][0];
    fill(inQueue, false); inQueue[0][0] = true;
    fill(done, false);
    set<iii> heap;
    heap.insert(mp(a[0][0], mp(0, 0)));
    while (!heap.empty()) {
        iii top = *heap.begin();
        heap.erase(top);
        int x = top.ss.ff, y = top.ss.ss, xx, yy, len;
        done[x][y] = true;
        rep(i, 4) {
            xx = x + dx[i], yy = y + dy[i], len = 0;
            while (inside(xx, yy) && ++len <= k) {
                if (a[xx][yy] > a[x][y] && !done[xx][yy]) {
                    f[xx][yy] = max(f[xx][yy], f[x][y] + a[xx][yy]);
                    res = max(res, f[xx][yy]);
                    if (!inQueue[xx][yy]) {
                        heap.insert(mp(a[xx][yy], mp(xx, yy)));
                        inQueue[xx][yy] = true;
                    }
                }
                xx += dx[i], yy += dy[i];
            }
        }
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d %d", &n, &k);
        rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
        cout << dijkstra() << endl;
        if (cases) puts("");
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
