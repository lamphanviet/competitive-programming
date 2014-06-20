//----------------------------
// LAM PHAN VIET
// UVA 11705 - Grasshopper
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define maxN 51
class Trampoline {
public:
    int r, c, cost;
    Trampoline() { r=c=cost=0; }
    Trampoline(int x, int y, int co) { r=x; c=y; cost=co; }
    void Get(int x, int y, int co) { r=x; c=y; cost=co; }
    void Get(Trampoline t) { r=t.r; c=t.c; cost=t.cost; }
};
int a[maxN][maxN], n, m;
char ans[maxN][maxN];
Trampoline Trace[maxN][maxN];

bool cmp(Trampoline a, Trampoline b) {
    if (a.cost<b.cost) return true;
    else if (a.cost==b.cost) return (a.r<b.r || (a.r==b.r && a.c<b.c));
    return false;
}

void BFS() {
    Trampoline u, v;
    queue<Trampoline> Queue;
    Queue.push(u);
    ans[0][0] = '*';
    Trace[0][0].Get(0, 0, 0);
    while (!Queue.empty()) {
        u = Queue.front();
        Queue.pop();
        
        for (int i=u.r+1, j=u.c; i<n; i++)
            if (a[i][j]==i-u.r && cmp(u, Trace[i][j])) {
                ans[i][j] = 'N';
                Trace[i][j].Get(u);
                Queue.push(Trampoline(i, j, u.cost+1));
            }
        for (int i=u.r-1, j=u.c; i>=0; i--)
            if (a[i][j]==u.r-i && cmp(u, Trace[i][j])) {
                ans[i][j] = 'S';
                Trace[i][j].Get(u);
                Queue.push(Trampoline(i, j, u.cost+1));
            }
        for (int i=u.r, j=u.c+1; j<m; j++)
            if (a[i][j]==j-u.c && cmp(u, Trace[i][j])) {
                ans[i][j] = 'W';
                Trace[i][j].Get(u);
                Queue.push(Trampoline(i, j, u.cost+1));
            }
        for (int i=u.r, j=u.c-1; j>=0; j--)
            if (a[i][j]==u.c-j && cmp(u, Trace[i][j])) {
                ans[i][j] = 'E';
                Trace[i][j].Get(u);
                Queue.push(Trampoline(i, j, u.cost+1));
            }
    }
}

main() {
//    freopen("705.inp", "r", stdin); freopen("705.out", "w", stdout);
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                scanf("%d", &a[i][j]);
                ans[i][j] = 'X';
                Trace[i][j].Get(maxN, maxN, 100000);
            }
        BFS();
        for (int i=0; i<n; i++) {
            ans[i][m] = '\0';
            puts(ans[i]);
        }
        printf("\n");
    }
}
