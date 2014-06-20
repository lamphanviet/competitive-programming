//----------------------------
// LAM PHAN VIET
// UVA 11940 - Face the Maze
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxS 100000
#define maxN 1005
#define maxM 100000
int r[maxM], c[maxM], n, m;
int a[maxN][maxN];
bool End, space;

void GetInput() {
    char s[maxS];
    int x, y, len;
    scanf("%d", &n);
    gets(s); len = strlen(s);
    int i = 0; m = 0;
    while (i<len) {
        while (i<len && s[i]!=' ') i++;
        while (i<len && s[i]==' ') i++;
        if (i<len) {
            sscanf(s+i, "(%d,%d)", &c[m], &r[m]);
            m++;
        }
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            a[i][j] = a[j][i] = 0; 
        }
    for (int i=2; i<m; i++)
        a[r[i]][c[i]] = 1;
}

bool isOK(int u, int v) {
    return (u>=1 && u<=n && v>=1 && v<=n);
}

bool Next(int u, int v) {
    if (u==r[1] && abs(v-c[1])==1) return true;
    if (v==c[1] && abs(u-r[1])==1) return true;
    return false;
}

bool isCCalled(int u, int v) {
    return (isOK(u, v) && a[u][v]==0);
}

void DFS(int u, int v) {
    if (End) return;
    if (!isOK(u, v) || a[u][v]==1) return;
    a[u][v] = 1;
    if (space) printf(" "); space = true;
    printf("(%d,%d)", v, u);
    
    if (Next(u, v)) {
        End = true;
        if (space) printf(" "); space = true;
        printf("(%d,%d)", c[1], r[1]);
        return;
    } 
    
    int k = 0;
    if (!End && isCCalled(u+1, v)) {
        DFS(u+1, v); k = 1;
    }
    
    if (!End && k) {
        if (space) printf(" "); space = true;
        printf("(%d,%d)", v, u);
    }
    k = 0;
    if (!End && isCCalled(u, v+1)) {
        DFS(u, v+1);  k = 1;
    }
    
    if (!End && k) {
        if (space) printf(" "); space = true;
        printf("(%d,%d)", v, u);
    }
    k = 0;
    if (!End && isCCalled(u, v-1)) {
        DFS(u, v-1); k = 1;
    }
    
    if (!End && k) {
        if (space) printf(" "); space = true;
        printf("(%d,%d)", v, u);
    }
    k = 0;
    if (!End && isCCalled(u-1, v)) {
        DFS(u-1, v); k = 1;
    }
    
    if (End) return;
    if (u==r[0] && v==c[0]) {
        if (k) {
            if (space) printf(" "); space = true;
            printf("(%d,%d)", v, u);
        }
        End = true;
        return;
    }
    if (k) {
            if (space) printf(" "); space = true;
            printf("(%d,%d)", v, u);
    }
}

void Print() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

main() {
//    freopen("940.inp", "r", stdin); freopen("940.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        GetInput();
        End = space = false;
//        Print();
        DFS(r[0], c[0]);
        printf("\n");
    }
}
