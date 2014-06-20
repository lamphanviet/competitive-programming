// UVA Problem 10000 - Longest Paths
// Link: 
#include <iostream>

using namespace std;

#define MAXN 102

int a[MAXN][MAXN],s,n;
int maxlen,maxpoint;

void Init() {
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            a[i][j] = a[j][i] = 0;
    maxlen = 0; maxpoint = s;
}

void BFS() {
    int d[n+2],Queue[10000];
    int u,v,front,rear;
    for (v=1;v<=n;v++) d[v] = 0;
    
    front = rear = 1;
    Queue[1] = s;
    while (front<=rear) {
        u = Queue[front++];
        for (v=1;v<=n;v++)
            if (a[u][v] && d[u]+1>d[v]) {
                d[v] = d[u]+1;
                Queue[++rear] = v;
                if (d[v]>maxlen) {
                    maxlen = d[v]; maxpoint = v;
                }
                else if (d[v]==maxlen && v<maxpoint) {
                    maxlen = d[v]; maxpoint = v;
                }
            }
    }
}

main() {
//    freopen("1000.inp","r",stdin);
//    freopen("1000.out","w",stdout);
    int u,v,kase = 0;
    while (cin >> n && n!=0) {
        cin >> s;
        Init();
        while (cin >> u >> v) {
            if (u==0 && v==0) break;
            a[u][v] = 1;
        }
        BFS();
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++kase,s,maxlen,maxpoint);
    }
}
