//*****************
// LAM PHAN VIET **
// UVA 10653 - Bombs! NO they are Mines!!
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
#include <string>
#include <vector>
using namespace std;

#define maxN 1002
#define INF 10000000
int n, m, a[maxN][maxN];
class Node {
public:
    int x, y;
    Node() { x=y=0; }
    Node(int a, int b) { x=a; y=b; }
    bool Check() {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    bool Get(int a, int b) {
        x=a; y=b;
        return Check();
    }
};
Node Start, End;

bool isOK(Node u, int cost) {
    if (a[u.x][u.y]==-1 || a[u.x][u.y]!=INF) return false;
    a[u.x][u.y] = cost+1;
    return true;
}

void BFS() {
    Node u, v;
    queue<Node> Queue;
    Queue.push(Start);
    while (!Queue.empty()) {
        u = Queue.front();
        Queue.pop();
        int cost = a[u.x][u.y];
        if (v.Get(u.x-1, u.y) && isOK(v, cost)) Queue.push(v);
        if (v.Get(u.x+1, u.y) && isOK(v, cost)) Queue.push(v);
        if (v.Get(u.x, u.y-1) && isOK(v, cost)) Queue.push(v);
        if (v.Get(u.x, u.y+1) && isOK(v, cost)) Queue.push(v);
    }
}

main() {
 //   freopen("653.inp", "r", stdin); freopen("653.out", "w", stdout);
    int k, row, u, col;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                a[i][j] = INF;
        scanf("%d", &k);
        while (k--) {
            scanf("%d %d", &row, &u);
            while (u--) {
                scanf("%d", &col);
                a[row][col] = -1;
            }
        }
        scanf("%d %d", &row, &col);
        Start.Get(row, col);
        a[row][col] = 0;
        scanf("%d %d", &row, &col);
        End.Get(row, col);
        BFS();
        printf("%d\n", a[End.x][End.y]);
    }
}
