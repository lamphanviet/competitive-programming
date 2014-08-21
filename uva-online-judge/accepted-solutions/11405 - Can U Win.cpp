//============================
// Author: lamphanviet@gmail.com
// Problem: 11405 - Can U Win
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
#define ff first
#define ss second

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

#define INF 1000111222
#define maxN 9

const int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int dy[] = { -1, 1, -1, 1, 2, -2, 2, -2};
const int n = 8;
int m, p[maxN][maxN], nPawn;
char s[maxN][maxN];
ii pawn[maxN];
int d[maxN][maxN][1 << 9];
int sx, sy;

struct Node {
    int x, y, state;
    Node() {}
    Node(int _x, int _y, int _state) {
        x = _x; y = _y; state = _state;
    }
    bool operator < (const Node &node) const {
        if (x == node.x) {
            if (y == node.y) {
                return state < node.state;
            }
            return y < node.y;
        }
        return x < node.x;
    }
    bool operator == (const Node &node) const {
        return (x == node.x && y == node.y && state == node.state);
    }
};

bool ok(int x, int y) {
    if (!(0 <= x && x < n && 0 <= y && y < n)) return false;
    return (s[x][y] != 'K' && s[x][y] != 'p');
}

bool dijkstra() {
    int bit = (1 << nPawn);
    rep(x, n) rep(y, n) rep(k, bit)
        d[x][y][k] = INF;
    d[sx][sy][0] = 0;
    set<pair<int, Node> > heap;
    heap.insert(mp(d[sx][sy][0], Node(sx, sy, 0)));
    while (!heap.empty()) {
        pair<int, Node> top = *heap.begin();
        heap.erase(top);
        int x = top.ss.x, y = top.ss.y, state = top.ss.state;
        if (d[x][y][state] > m) return false;
        //printf("%d %d: %d %d\n", x, y, state, d[x][y][state]);
        if (state == bit - 1) return d[x][y][state] <= m;
        rep(i, 8) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int newState = state;
            
            if (!ok(xx, yy)) continue;
            
            if (p[xx][yy] >= 0) {
                int k = 1 << p[xx][yy];
                newState |= k;
            }
            
            if (d[xx][yy][newState] > d[x][y][state] + 1) {
                heap.erase(mp(d[xx][yy][newState], Node(xx, yy, newState)));
                d[xx][yy][newState] = d[x][y][state] + 1;
                heap.insert(mp(d[xx][yy][newState], Node(xx, yy, newState)));
            }
        }
    }
    return false;
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int cases;
    for (scanf("%d", &cases); cases--; ) {
        nPawn = 0;
        scanf(" %d ", &m);
        rep(i, n) {
            scanf(" %s ", s[i]);
            rep(j, n) {
                p[i][j] = -1;
                if (s[i][j] == 'P') { // pawn
                    p[i][j] = nPawn;
                    pawn[nPawn++] = mp(i, j);
                }
                if (s[i][j] == 'k') sx = i, sy = j;
            }
        }
        if (dijkstra()) puts("Yes");
        else puts("No");
    }
    return 0;
}
