//*****************
// LAM PHAN VIET **
// UVA 11953 - Battleships
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 105
int n;
char s[maxN][maxN];

bool isOK(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<n);
}

bool DFS(int x, int y, int len) {
    if (isOK(x, y) && s[x][y]!='.' && len<=(int)(n/2)) {
        char ch = s[x][y];
        s[x][y] = '.';
        bool d1 = DFS(x+1, y, len+1);
        bool d2 = DFS(x, y+1, len+1);
        if (ch=='x') return true;
        else if (d1 || d2) return true;
        return false;
    }
    return false;
}

main() {
 //   freopen("cc.inp", "r", stdin); freopen("cc.out", "w", stdout);
    int Case, Count;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d", &n); gets(s[0]);
        for (int i=0; i<n; i++)
            gets(s[i]);
        Count = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (s[i][j]=='x' || s[i][j]=='@') {
                    if (DFS(i, j, 1)) {
                        Count++;
                    }
                }
        printf("Case %d: %d\n", kk, Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
