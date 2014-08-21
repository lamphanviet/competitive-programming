//----------------------------
// LAM PHAN VIET
// UVA 572 - Oil Deposits
// Time limit: 3s
//----------------------------
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAXN 105

int n, m;
char a[MAXN][MAXN];

void DFS(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m || a[x][y]!='@') return;
    a[x][y] = '0';
    DFS(x-1,y-1); DFS(x-1,y); DFS(x-1,y+1);
    DFS(x,y-1);               DFS(x,y+1);
    DFS(x+1,y-1); DFS(x+1,y); DFS(x+1,y+1);
}

main() {
//    freopen("572.inp","r",stdin);
//    freopen("572.out","w",stdout);
    int i, j;
    while (cin >> n >> m) {
        if (n==0 && m==0) break;
        getchar();
        for (i=0;i<n;i++)
            gets(a[i]);
        int count = 0;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (a[i][j]=='@') {
                    count++;
                    DFS(i,j);
                }
        cout << count << endl;
    }
}
