//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12295 - Optimal Symmetric Paths
// Time limit: 1.000s
//=============================//
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
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define MOD 1000000009
#define INF 500000000
#define maxN 110
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, a[maxN][maxN];
int d[maxN][maxN], way[maxN][maxN];
bool Free[maxN][maxN];

bool isEnd(int i, int j) { return (i + j == n + 1); }

bool isInside(int x, int y) {
    if (x < 1 || x > n) return false;
    if (y < 1 || y > n) return false;
    return (y <= n - x + 1);
}

void solve() {
    FOR (i, 1, n) {
        FOR (j, 1, n) {
            d[i][j] = INF;
            Free[i][j] = true;
            way[i][j] = 0;
        }
    }
    int x, y, xx, yy;
    set<iii> heap;
    d[1][1] = a[1][1];
    way[1][1] = 1;
    heap.insert(iii(d[1][1], ii(1, 1)));
    while (!heap.empty()) {
        iii top = *heap.begin();
        heap.erase(top);
        x = top.ss.ff;
        y = top.ss.ss;
        Free[x][y] = false;
        REP(i, 4) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (!isInside(xx, yy)) continue;
            int cost = d[x][y] + a[xx][yy];
            if (Free[xx][yy] && cost <= d[xx][yy]) {
                if (cost < d[xx][yy]) {
                    if (d[xx][yy] != INF)
                        heap.erase(iii(d[xx][yy], ii(xx, yy)));
                    d[xx][yy] = cost;
                    heap.insert(iii(d[xx][yy], ii(xx, yy)));
                    way[xx][yy] = 0;
                }
                way[xx][yy] +=way[x][y];
                way[xx][yy] %= MOD;
            }
        }
    }
    int Min = INF, result = 0;
    FOR (i, 1, n)
        Min = min(d[i][n + 1 - i], Min);
    FOR (i, 1, n)
        if (d[i][n + 1 - i] == Min) {
            result += way[i][n + 1 - i];
            result %= MOD;
        }
    printf("%d\n", result);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) FOR (j, 1, n)
            scanf("%d", &a[i][j]);
        FOR (i, 1, n) {
            int k = n - i + 1;
            FOR (j, 1, k - 1)
                a[i][j] += a[n + 1 - j][n + 1 - i];
        }
        solve();
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
