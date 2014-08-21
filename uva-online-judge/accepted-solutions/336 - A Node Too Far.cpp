// 336 - A Node Too Far
#include <iostream>

using namespace std;

#define MAXN 33

int n, m, num[MAXN];
bool a[MAXN][MAXN];
int dem;

int GetPos(int u) {
    for (int i=1;i<=n;i++)
        if (u==num[i]) return i;
    num[++n] = u;
    return n;
}

void Enter() {
    int i, j, u, v;
    for (i=1;i<=MAXN;i++)
        for (j=i;j<=MAXN;j++)
            a[i][j] = a[j][i] = false;
    n = 0;
    for (i=1;i<=m;i++) {
        cin >> u >> v;
        u = GetPos(u);
        v = GetPos(v);
        a[u][v] =a[v][u] = true;
    }
}

void BFS(int cs, int start, int ttl) {
    int Queue[n+2], front , rear;
    int u,v, d[n+2];
    bool Free[n+2];
    for (v=1;v<=n;v++) {
        Free[v] = true; d[v] = -1;
    }
    Free[start] = false; d[start] = ttl;
    Queue[1] =start;
    front = rear = 1;
    while (front<=rear) {
        u = Queue[front++];
        for (v=1;v<=n;v++)
            if (Free[v] && a[u][v]) {
                Free[v] = false;
                d[v] = d[u]-1;
                if (d[v]>0) Queue[++rear] = v;
            }
    }
    dem = 0;
    for (v=1;v<=n;v++)
        if (d[v]<0) dem++;
}

main() {
//    freopen("336.inp","r",stdin);
//    freopen("336.out","w",stdout);
    int start, ttl, kase = 0;
    while (cin >> m) {
        if (m==0) break;
        Enter();
        while (cin >> start >> ttl) {
            if (start==0 && ttl==0) break;
            BFS(start,GetPos(start),ttl);
            kase++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", kase, dem, start, ttl);
        }
    }
}
