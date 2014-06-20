//*****************
// LAM PHAN VIET **
// UVA 929 - Number Maze
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
#define INF 1000000
class Node {
public:
    int x, y;
    Node() { x=y=0; }
    Node(int a, int b) { x=a; y=b; }
};
const int change[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int n, m, a[maxN][maxN];
int d[maxN][maxN], Pos[maxN][maxN], nHeap;
Node Heap[maxN*maxN];
bool Free[maxN][maxN];

bool isOK(int x, int y) {
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void UpdateHeap(Node v) {
    int child, parent;
    child = Pos[v.x][v.y];
    if (child==0) child = ++nHeap;
    parent = child/2;
    while (parent>0 && d[Heap[parent].x][Heap[parent].y] > d[v.x][v.y]) {
        Heap[child] = Heap[parent];
        Pos[Heap[child].x][Heap[child].y] = child;
        child = parent;
        parent = child/2;
    }
    Heap[child] = v;
    Pos[v.x][v.y] = child;
}

Node PopHeap() {
    Node pop = Heap[1];
    Node v = Heap[nHeap--];
    int r = 1;
    while (r+r<=nHeap) {
        int c = r+r;
        if (c<nHeap && d[Heap[c+1].x][Heap[c+1].y] < d[Heap[c].x][Heap[c].y]) c++;
        if (d[Heap[c].x][Heap[c].y]>=d[v.x][v.y]) break;
        Heap[r] = Heap[c];
        Pos[Heap[r].x][Heap[r].y] = r;
        r = c;
    }
    Heap[r] = v;
    Pos[v.x][v.y] = r;
    return pop;
}

void Dijkstra() {
    d[1][1] = a[1][1];
    UpdateHeap(Node(1, 1));
    do {
        Node u = PopHeap();
        if (u.x==n && u.y==m) return;
        Free[u.x][u.y] = false;
        For (k, 0, 3) {
            int x = u.x+change[k][0], y = u.y+change[k][1];
            if (!Free[x][y] || !isOK(x, y)) continue;
            int val = d[u.x][u.y] + a[x][y];
            if (val < d[x][y]) {
                d[x][y] = val;
                UpdateHeap(Node(x, y));
            }
        }
    } while (nHeap!=0);
}

main() {
 //   freopen("929.inp", "r", stdin); freopen("929.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++) {
                scanf("%d", &a[i][j]);
                d[i][j] = INF;
                Free[i][j] = true;
                Pos[i][j] = 0;
            }
        nHeap = 0;
        Dijkstra();
        printf("%d\n", d[n][m]);
    }
}
