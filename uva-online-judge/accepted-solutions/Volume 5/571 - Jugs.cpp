//*****************
// LAM PHAN VIET **
// UVA 571 - Jugs
// Time limit: 3.000s
//********************************
#include <algorithm>
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
#define maxN 1001
using namespace std;

class Node {
public:
    int x, y;
    Node() { x = y = 0; }
    Node(int a, int b) { x = a; y = b; }
};
int A, B, N;
int c[maxN][maxN], a[maxN][maxN];
Node trace[maxN][maxN];
queue<Node> Q;

void try_push(int x, int y, int val, Node u, int k) {
    if (c[x][y] != INF) return;
    c[x][y] = val + 1;
    trace[x][y] = u;
    a[x][y] = k;
    Q.push(Node(x, y));
}

Node bfs() {
    Q = queue<Node>();
    c[0][0] = 0;
    Q.push(Node(0, 0));
    while (!Q.empty()) {
        Node u = Q.front(); Q.pop();
        int x = u.x, y = u.y, val = c[x][y];
        if (x == N || y == N) return u;
        
        try_push(A, y, val, u, 1);
        try_push(x, B, val, u, 2);
        try_push(0, y, val, u, 3);
        try_push(x, 0, val, u, 4);
        // pour A B
        int w = min(x, B - y);
        try_push(x - w, y + w, val, u, 5);
        // pour B A
        w = min(y, A - x);
        try_push(x + w, y - w, val, u, 6);
    }
}

void result(Node u) {
    int x = u.x, y = u.y;
    vector<int> res;
    while (c[x][y]) {
        res.pb(a[x][y]);
        u = trace[x][y];
        x = u.x, y = u.y;
    }
    for (int i = res.size()-1; i >= 0; i--)
        switch (res[i]) {
            case 1: puts("fill A"); break;
            case 2: puts("fill B"); break;
            case 3: puts("empty A"); break;
            case 4: puts("empty B"); break;
            case 5: puts("pour A B"); break;
            case 6: puts("pour B A"); break;
        }
    puts("success");
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d %d", &A, &B, &N) != EOF) {
        FOR (i, 0, B)
            FOR (j, 0, B)
                c[i][j] = INF;
        result(bfs());
    }
}

/* lamphanviet@gmail.com - 2011 */
