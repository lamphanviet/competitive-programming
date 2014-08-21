// UVA Problem 352 - The Seasonal War
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=288
#include <iostream>

using namespace std;

#define MAXN 30

char a[MAXN][MAXN];
int n;

void DFS(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=n || a[i][j]!='1') return;
    a[i][j] = '2';
    DFS(i-1,j-1); DFS(i-1,j); DFS(i-1,j+1);
    DFS(i,j-1);           DFS(i,j+1);
    DFS(i+1,j-1); DFS(i+1,j); DFS(i+1,j+1);
}

main() {
//    freopen("352.inp","r",stdin);
//    freopen("352.out","w",stdout);
    int i,j,count,kase;
    kase = 0;
    while (cin >> n) {
        getchar();
        for (i=0;i<n;i++)
            gets(a[i]);
        count=0;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (a[i][j]=='1') {
                    count++;
                    DFS(i,j);
                }
//        for (i=0;i<n;i++)
//            puts(a[i]);
        printf("Image number %d contains %d war eagles.\n",++kase,count);
    }
}
