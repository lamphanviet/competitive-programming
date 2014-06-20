// UVA Problem 469 - Wetlands of Florida
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=410
#include <iostream>
#include <string.h>

using namespace std;

#define MAXLEN 105

int n,m, dem;
char a[MAXLEN][MAXLEN];
int ch[MAXLEN][MAXLEN];

void DFS(int x, int y) {
    if (x<1 || x>n || y<0 || y>=m || a[x][y]!='W' || ch[x][y]) return;
    ch[x][y] = 1;
    dem++;
    
    DFS(x-1,y-1); DFS(x-1,y); DFS(x-1,y+1);
    DFS(x,y-1);               DFS(x,y+1);
    DFS(x+1,y-1); DFS(x+1,y); DFS(x+1,y+1);
}

void Init() {
    for (int i=1;i<=n;i++)
        for (int j=0;j<m;j++)
            ch[i][j] = 0;
}

void Enter_Solve() {
    int x,y;
    char s[10];
    
    n = 0;
    while (gets(a[++n]))
        if (!(a[n][0]=='W' || a[n][0]=='L')) {
            n--; break;
        }
    m = strlen(a[1]);
    strcpy(s,a[n+1]);
    do {
        if (strlen(s)==0) break;
        sscanf(s,"%d %d",&x,&y);
        dem = 0;
        Init();
        DFS(x,y-1);
        cout << dem << endl;
    } while (gets(s)); 
}


main() {
//    freopen("469.inp","r",stdin);
//    freopen("469.out","w",stdout);
    int kase;
    bool End = false;
    cin >> kase;
    getchar(); getchar();
    while (kase--) {
        if (End) cout << endl;
        End =  true;
        Enter_Solve();
    }
}
