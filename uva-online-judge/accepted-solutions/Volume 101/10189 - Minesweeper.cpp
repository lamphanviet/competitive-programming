//----------------------------
// LAM PHAN VIET
// UVA 10189 - Minesweeper
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 105
char s[maxN][maxN], ans[maxN][maxN];
int n, m;

bool isInside(int i, int j) {   // Kiem tra xem vi tri o co hop le khong
    return (0<=i && i<n && 0<=j && j<m);
}

main() {
    int kase = 0;
    bool Line = false;
    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) break;
        gets(s[0]);
        for (int i=0; i<n; i++) {
            gets(s[i]);
            for (int j=0; j<m; j++)
                ans[i][j] = '0';
        }
        
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (s[i][j]=='*') {
                    ans[i][j] = '*';
                    for (int u=i-1; u<=i+1; u++)
                        for (int v=j-1; v<=j+1; v++)
                            if (isInside(u, v) && ans[u][v]!='*')
                                ans[u][v]++;
                }
        if (Line) printf("\n");
        Line = true;
        printf("Field #%d:\n", ++kase);
        for (int i=0; i<n; i++) {
            ans[i][m] = '\0';   // Ki tu 'dau xuong dong'
            puts(ans[i]);
        }
    }
}
