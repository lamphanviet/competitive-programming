// UVA Problem 10307 - Killing Aliens in Borg Maze
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1248
#include <iostream>

using namespace std;

#define INF 99
#define MAXS 55
#define MAXN 105

char s[MAXS][MAXS];
int a[MAXN][MAXN], n, sum;
int nn, mm, cs[MAXS][MAXS];

void Enter() {
    cin >> mm >> nn; getchar();
    int i,j;
    for (i=0;i<nn;i++)
        gets(s[i]);
    
    n = 0;
    for (i=0;i<nn;i++)
        for (j=0;j<mm;j++) {
            cs[i][j] = 0;
            if (s[i][j]=='A' || s[i][j]=='S') {
                cs[i][j] = ++n;
            }
        }
}

void Init_Main() {
    for (int i=1;i<=n;i++) {
        a[i][i] = 0;
        for (int j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = INF;
    }
}

void BFS(int x, int y) {
    
    int Qx[10005],Qy[10005], front,rear;
    int bfs[nn+2][mm+2];
    int u, v, start;
    for (u=0;u<nn;u++)
        for (v=u;v<mm;v++)
            bfs[u][v] = bfs[v][u] = INF;
    bfs[x][y] = 0;
    front = rear = 1; 
    Qx[1] = x; Qy[1] = y; start = cs[x][y];
    
    while (front<=rear) {
        u = Qx[front]; v = Qy[front++];
        // (u) (v-1)
        if (s[u][v-1]!='#' && bfs[u][v-1]>bfs[u][v]+1) {
            Qx[++rear] = u; Qy[rear] = v-1;
            bfs[u][v-1] = bfs[u][v]+1;
            if (s[u][v-1]!=' ' && bfs[u][v-1]<a[start][cs[u][v-1]])
                a[start][cs[u][v-1]] = bfs[u][v-1];
        }
        // (u) (v+1)
        if (s[u][v+1]!='#' && bfs[u][v+1]>bfs[u][v]+1) {
            Qx[++rear] = u; Qy[rear] = v+1;
            bfs[u][v+1] = bfs[u][v]+1;
            if (s[u][v+1]!=' ' && bfs[u][v+1]<a[start][cs[u][v+1]])
                a[start][cs[u][v+1]] = bfs[u][v+1];
        }
        // (u-1) (v)
        if (s[u-1][v]!='#' && bfs[u-1][v]>bfs[u][v]+1) {
            Qx[++rear] = u-1; Qy[rear] = v;
            bfs[u-1][v] = bfs[u][v]+1;
            if (s[u-1][v]!=' ' && bfs[u-1][v]<a[start][cs[u-1][v]])
                a[start][cs[u-1][v]] = bfs[u-1][v];
        }
        // (u+1) (v)
        if (s[u+1][v]!='#' && bfs[u+1][v]>bfs[u][v]+1) {
            Qx[++rear] = u+1; Qy[rear] = v;
            bfs[u+1][v] = bfs[u][v]+1;
            if (s[u+1][v]!=' ' && bfs[u+1][v]<a[start][cs[u+1][v]])
                a[start][cs[u+1][v]] = bfs[u+1][v];
        }
    }
    
/*    cout << "mang bfs" << endl;
    for (int i=0;i<nn;i++) {
        for (int j=0;j<mm;j++)
            printf("%4d",bfs[i][j]);
        cout << endl;
    }   */
}

void Print() {
    int i,j;
    cout << "chi so" << endl;
    for (i=0;i<nn;i++) {
        for (j=0;j<mm;j++)
            printf("%4d",cs[i][j]);
        cout << endl;
    }
    cout << "mang main a" << endl;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        cout << endl;
    }
}

/*----------------------------------PRIM------------------------------------------*/
void Prim() {
    int u,v,k;
    int d[n+2], Trace[n+2], min;
    bool Free[n+2];
    for (v=1;v<=n;v++) {
        d[v]=INF; Free[v]=true;
    }
    d[1] = 0;
    
    for (k=1;k<=n;k++) {
        u = 0; min = INF;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]<min) {
                u = v; min = d[v];
            }
        Free[u] = false;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]>a[u][v]) {
                d[v] = a[u][v];
                Trace[v] = u;
            }
    }
    sum = 0;
    for (v=2;v<=n;v++)
        sum += a[v][Trace[v]];
}

/*------------------------------------------MAIN-------------------------------------------------------*/
main() {
//    freopen("307.inp","r",stdin);
//    freopen("307.out","w",stdout);
    
    int kase,i,j;
    cin >> kase;
    while (kase--) {
//        printf("CASE %d\n",kase);
        Enter();
        Init_Main();
        for (i=0;i<nn;i++)
            for (j=0;j<mm;j++)
                if (cs[i][j]!=0) {
                    BFS(i,j);
//                    Print_DFS();
                }
//        Print();
        Prim();
        cout << sum << endl;
    }
}
