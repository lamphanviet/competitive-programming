// UVA Problem 11841 - Y-game
// Link http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2941
#include <iostream>

using namespace std;

int n,a[25][25];
bool Black,c2,c3;

void Init() {
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n-i;j++)
            a[i][j] = 0;
}

void DFS(int u, int v) {
    if (Black) return;
    if (!(u>=0 && v>=0 && (u+v)<=n && a[u][v]==1)) return;
    
    a[u][v]=2;
    if (u==0) c2 = true;
    if (u+v==n) c3 = true;
    if (c2 && c3) {
        Black = true; return;
    }
    
    DFS(u-1,v); DFS(u-1,v+1);
    DFS(u,v-1); DFS(u,v+1);
    DFS(u+1,v-1); DFS(u+1,v);
}

void Print() {
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n-i;j++)
            printf("%3d",a[i][j]);
        cout << endl;
    }
}

main() {
//    freopen("841.inp","r",stdin);
//    freopen("841.out","w",stdout);
    int m,i,u,v,x;
    while (cin >> n >> m) {
        if (n==0 && m==0) break;
        Init();
        for (i=1;i<=m;i++) {
            cin >> u >> v >> x;
            a[u][v]=1;
        }
        Black = false;
        for (i=0;i<=n && !Black;i++) 
            if (a[i][0]==1) {
                Black = c2 = c3 = false;
                DFS(i,0);
 //               Print();
            }
        if (Black) cout << "Benny";
        else cout << "Willy";
        cout << endl;
 //       Print();
    }
}
