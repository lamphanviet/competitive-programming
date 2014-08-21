//*****************
// LAM PHAN VIET **
// UVA 10047 - The Monocycle
// Time limit: 3.000
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define INF 500000000
#define maxN 30
using namespace std;

class Node {
public:
    int x, y, dr, cl;
    Node(int xx, int yy, int d, int c) {
        x = xx; y = yy;
        dr = d; cl = c;
    }
};
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int k[] = { 1, 3 };
int n, m, d[maxN][maxN][4][5];
char s[maxN][maxN];

bool isInside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(int x, int y) {
    queue<Node> Q;
    Q.push(Node(x, y, 0, 0));
    d[x][y][0][0] = 0;
    while (!Q.empty()) {
        Node u = Q.front(); Q.pop();
        int val = d[u.x][u.y][u.dr][u.cl];
        if (s[u.x][u.y] == 'T' && !u.cl) return val;

        x = u.x + dx[u.dr];
        y = u.y + dy[u.dr];
        int cl = (u.cl + 1) % 5;
        if (isInside(x, y) && d[x][y][u.dr][cl]==INF && s[x][y]!='#') {
            d[x][y][u.dr][cl] = val + 1;
            Q.push(Node(x, y, u.dr, cl));
        }
        
        REP(i, 2) {
            int dr = (u.dr + k[i]) % 4;
            if (d[u.x][u.y][dr][u.cl]==INF) {
                d[u.x][u.y][dr][u.cl] = val + 1;
                Q.push(Node(u.x, u.y, dr, u.cl));
            }
        }
    }
    return -1;
}

main() {
//    FileIn("test"); FileOut("test");
    int x, y, Case = 0;
    while (scanf("%d %d ", &n, &m) && (n || m)) {
        REP(i, n) {
            gets(s[i]);
            REP(j, m) {
                if (s[i][j]=='S')
                    x = i, y = j;
                REP(k, 4)
                    REP(t, 5)
                        d[i][j][k][t] = INF;
            }
        }
        int res = bfs(x, y);
        
        if (Case) printf("\n");
        printf("Case #%d\n", ++Case);
        if (res < 0) puts("destination not reachable");
        else printf("minimum time = %d sec\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
