// UVA Problem 459 - Graph Connectivity
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=400
#include <iostream>

using namespace std;

#define MAXN 30
#define move 65

int n,a[MAXN][MAXN];
bool Free[MAXN];

void DFS(int u) {
    Free[u] =false;
    for (int v=0;v<n;v++)
        if (a[u][v] && Free[v]) DFS(v);
}

main() {
//    freopen("459.inp","r",stdin);
//    freopen("459.out","w",stdout);
    int kase,u,v,i,j;
    char s[5];
    cin >> kase; scanf(" ");
    while (kase--) {
        gets(s);
        if (strlen(s)==0) break;
        n = s[0]-move+1;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                a[i][j] = 0;
        while (gets(s) && strlen(s)!=0) {
            u = s[0]-65; v = s[1]-65;
            a[u][v] = a[v][u] = 1;
  //          puts(s);
        }
        
 /*       for (i=0;i<n;i++) {
            for (j=0;j<n;j++)
                printf("%3d",a[i][j]);
            cout << endl;
        }   */
        
        memset(Free,true,n+2);
        int count = 0;
        for (i=0;i<n;i++)
            if (Free[i]) {
                count++;
                DFS(i);
            }
    
        cout << count << endl;
        if (kase) cout << endl;
    }
}
