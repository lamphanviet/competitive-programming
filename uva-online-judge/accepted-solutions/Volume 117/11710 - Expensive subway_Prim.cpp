// UVA Problem 11710 - Expensive subway
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2757
#include <iostream>
#include <string.h>

using namespace std;

#define MAXN 405
#define INF 20000000

long n,m,sum, a[MAXN][MAXN];
char name[MAXN][12];
bool Connected;

int Station(char s[]) {
    int k=1;
    while (strcmp(s,name[k])!=0) k++;
    return k;
}

void Init() {
    for (int i=1;i<=n;i++) {
        a[i][i] = 0;
        for (int j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = INF;
    }
}

void Enter() {
    scanf(" ");
    int i,u,v, price;
    char sa[12],sb[12];
    for (i=1;i<=n;i++) {
        gets(name[i]);
    }
    for (i=1;i<=m;i++) {
        scanf("%s %s %d",&sa,&sb,&price);
        u = Station(sa); v = Station(sb);
        a[u][v] = a[v][u] = price;
    }
    getchar(); gets(sa);
}

/*----------------Prim---------------------*/

void Prim() {
    long d[n+3], min;
    int k,u,v;
    bool Free[n+3];
    for (k=1;k<=n;k++) {
        Free[k] = true; d[k] = INF;
    }
    d[1] = 0; sum = 0;
    for (k=1;k<=n;k++) {
        u = 0; min = INF;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]<min) {
                u = v; min = d[v];
            }
        if (u==0) return;
        Free[u] = false;
        for (v=1;v<=n;v++)
            if (Free[v] && a[u][v]<d[v])
                d[v] = a[u][v];
    }
    
    for (k=2;k<=n;k++)
        sum += d[k];
    
    Connected = true;
}

main() {
//    freopen("710.inp","r",stdin);
//    freopen("710.out","w",stdout);
    while (cin >> n >> m) {
        if (n==0 && m==0) break;
        Init();
        Enter();
        Connected = false;
        if (m>=n-1) Prim();

        if (Connected) cout << sum;
        else cout << "Impossible";
        cout << endl;
    }
}
