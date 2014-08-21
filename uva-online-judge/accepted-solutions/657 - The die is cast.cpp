// 657 - The die is cast
#include <iostream>

char s[55][55];
int n, m, dem;

using namespace std;

void DFS_Dot(int u, int v) {
    if (u<0 || u>=m || v<0 || v>=n || s[u][v]!='X') return;
    s[u][v] = '*';
    DFS_Dot(u-1, v); DFS_Dot(u+1, v);
    DFS_Dot(u, v-1); DFS_Dot(u, v+1);
}

void DFS_Dice(int u, int v) {
    if (u<0 || u>=m || v<0 || v>=n || s[u][v]=='.') return;
    if (s[u][v]=='X') {
        dem++; DFS_Dot(u, v);
    }
    s[u][v]='.';
    DFS_Dice(u-1, v); DFS_Dice(u+1, v);
    DFS_Dice(u, v-1); DFS_Dice(u, v+1);
}


main() {
//    freopen("657.inp", "r", stdin); freopen("657.out", "w", stdout);
    int i, j, ans[2000], nans, kase=0;
    while (cin >> n >> m) {
        if (!n && !m) break;
        gets(s[0]);
        for (i=0; i<m; i++)
            gets(s[i]);
        nans = 0;
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                if (s[i][j]!='.') {
                    dem = 0;
                    DFS_Dice(i, j);
                    ans[nans++] = dem;
                }
        sort(ans, ans+nans);
        printf("Throw %d\n", ++kase);
        if (nans>0) printf("%d", ans[0]);
        for (i=1; i<nans; i++) printf(" %d", ans[i]);
        cout << endl << endl;
    }
}
