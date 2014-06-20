// UVA Problem 11792 - Krochanska is Here!
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2892
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define MAXN 10010

int a[MAXN][MAXN], connect[MAXN];
bool Free[MAXN];
int n,krochan,min1;

void Enter() {
    int m,x,y,i;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        a[i][0] = connect[i] = 0;
    while (m--) {
        cin >> x; connect[x]++;
        if (!x) continue;
        while (cin >> y && y!=0) {
            a[ x ][ ++a[x][0] ] = y;
            a[ y ][ ++a[y][0] ] = x;
            connect[y]++;
            x = y;
        }
    }
}

void BFS(int u) {
    int uu,v,tempmin,k;
    int Queue[n+5],front,rear;
    int d[n+5];
    front=rear=1; tempmin=0;
    Queue[1]=uu=u;
    memset(Free,true,n+5);
    d[u] = 0; Free[u]=false;
    while (front<=rear) {
        u = Queue[front++];
        for (k=1;k<=a[u][0];k++)
            if (Free[a[u][k]]) {
                v = a[u][k];
                d[v] = d[u]+2;
                if (connect[v]>1) tempmin+=d[v];
                Queue[++rear] = v;
                Free[v]=false;
            }
    }
 //   printf("bfs u %d tempmin %d\n",uu,tempmin);
 //   for (int i=1;i<=rear;i++)
 //       printf("%3d ",Queue[i]);
 //   cout << endl;
    if (tempmin<min1) {
        min1 = tempmin;
        krochan = uu;
    }
}

main() {
//    freopen("792.inp","r",stdin);
//    freopen("792.out","w",stdout);
    
    int kase;
    cin >> kase;
    while (kase--) {
        Enter();
        min1 = 99999999;
        krochan = 0;
        for (int i=1;i<=n;i++)
            if (connect[i]>1) BFS(i);
        cout << "Krochanska is in: " << krochan << endl;
/*        for (int i=1;i<=n;i++) {
            printf("%4d:",i);
            for (int j=1;j<=a[i][0];j++)
                printf("%4d",a[i][j]);
            cout << endl;
        }*/
    }
}
