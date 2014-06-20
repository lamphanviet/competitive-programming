//----------------------------
// LAM PHAN VIET
// UVA 782 - Contour Painting
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 50
#define maxM 100
int n, m[maxM], mm;
char s[maxN][maxM];
bool Free[maxN][maxM];

bool isOK(int i, int j) {
    return (i>=1 && i<n && j>=0 && j<mm);
}

bool canfill(int u, int v) {
    if (isOK(u-1, v) && s[u-1][v]!=' ' && s[u-1][v]!='#') return true;
    if (isOK(u+1, v) && s[u+1][v]!=' ' && s[u+1][v]!='#') return true;
    if (isOK(u, v-1) && s[u][v-1]!=' ' && s[u][v-1]!='#') return true;
    if (isOK(u, v+1) && s[u][v+1]!=' ' && s[u][v+1]!='#') return true;
    return false;
}

void DFS(int u, int v) {
    if (!isOK(u, v) || s[u][v]!=' ' || !Free[u][v]) return;
    if (canfill(u, v)) {
        s[u][v] = '#';
        m[u] = max(m[u], v+1);
    }
    Free[u][v] = false;
    DFS(u-1, v); DFS(u, v-1);
    DFS(u+1, v); DFS(u, v+1);
}

main() {
 //   freopen("782.inp", "r", stdin); freopen("782.out", "w", stdout);
    int Case, x, y;
    scanf("%d", &Case); gets(s[0]);
    while (Case--) {
        n = mm = 0;
        while (gets(s[++n])) {
            m[n] = strlen(s[n]);
            mm = max(mm, m[n]);
            if (s[n][0] == '_') break;
        }
        mm++;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m[i]; j++) {
                if (s[i][j]=='*') {
                    x=i; y=j;
                }
                Free[i][j] = true;
            }
            for (int j=m[i]; j<mm; j++) {
                s[i][j] = ' ';
                Free[i][j] = true;
            }
        }
        m[n+1] = 0;
        s[x][y] = ' ';
        DFS(x, y);
        for (int i=1; i<=n; i++) {
            int j=mm;
            while (s[i][j-1]==' ') j--;
            s[i][j] = '\0';
            puts(s[i]);
        }
    }
}
