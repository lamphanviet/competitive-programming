/*****************/
/* LAM PHAN VIET */
/* UVA 321 - The New Villa
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 11
using namespace std;

class Node {
public:
    int u, x;
    Node() {}
    Node(int a, int b) { u = a; x = b; }
};
int n, d[maxN][bit(maxN)], a[maxN][bit(maxN)];;
bool c[maxN][maxN], light[maxN][maxN];
Node trace[maxN][bit(maxN)];

void initialize() {
    Fill(c, false);
    Fill(light, false);
    FOR (i, 1, n)
        FOR (j, 0, bit(n+1))
            d[i][j] = INF;
}

void bfs() {
    queue<Node> Q;
    d[1][bit(1)] = 0;
    Q.push(Node(1, bit(1)));
    while (!Q.empty()) {
        Node u_node = Q.front(); Q.pop();
        int u = u_node.u, x = u_node.x;
        if (u == n && x == bit(n)) break;
        
        FOR (v, 1, n)
            if (c[u][v] && d[v][x] == INF && (x & bit(v)) == bit(v)) {
                d[v][x] = d[u][x] + 1;
                trace[v][x] = u_node;
                a[v][x] = v + n;
                Q.push(Node(v, x));
            }
        
        FOR (v, 1, n)
            if (v != u && light[u][v]) {
                int xx = x, k = 1;
                if ((xx & bit(v)) == bit(v))
                    xx -= bit(v), k = -1;
                else xx += bit(v);
                if (d[u][xx] == INF) {
                    d[u][xx] = d[u][x] + 1;
                    trace[u][xx] = u_node;
                    a[u][xx] = k * v;
                    Q.push(Node(u, xx));
                }
            }
    }
}

void result(int &Case) {
    printf("Villa #%d\n", ++Case);
    
    if (d[n][bit(n)] == INF) {
        puts("The problem cannot be solved.");
        return;
    }
    vector<int> res;
    Node u_node = Node(n, bit(n));
    while (u_node.u != 1 || u_node.x != bit(1)) {
        res.pb(a[u_node.u][u_node.x]);
        u_node = trace[u_node.u][u_node.x];
    }
    printf("The problem can be solved in %d steps:\n", res.size());
    for (int i = res.size() - 1; i >= 0; i--)
        if (res[i] > n) printf("- Move to room %d.\n", res[i] - n);
        else if (res[i] > 0) printf("- Switch on light in room %d.\n", res[i]);
        else printf("- Switch off light in room %d.\n", -res[i]);
}

main() {
//    FileIn("test"); FileOut("test");
    int m, k, u, v, Case = 0;
    while (scanf("%d %d %d", &n, &m, &k) && (n || m || k)) {
        initialize();
        while (m--) {
            scanf("%d %d", &u, &v);
            c[u][v] = c[v][u] = true;
        }
        while (k--) {
            scanf("%d %d", &u, &v);
            light[u][v] = true;
        }
        bfs();
        result(Case);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
