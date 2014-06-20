//*****************
// LAM PHAN VIET **
// UVA - 315 - Network
// Time limit:
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 102
int n, Parent[maxN], nChildren[maxN];
int Number[maxN], Low[maxN], Count;
bool a[maxN][maxN], IsCut[maxN];

void Visit(int u) {
    Number[u] = ++Count;
    Low[u] = n+1;
    for (int v=1; v<=n; v++)
        if (a[u][v]) {
            a[v][u] = false;
            if (Parent[v]) Low[u] = min(Low[u], Number[v]);
            else {
                Parent[v] = u;
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
        }
}

main() {
//    freopen("315.inp", "r", stdin); freopen("315.out", "w", stdout);
    char s[10000];
    while (scanf("%d", &n) && n) {
        // Init
        for (int i=1; i<=n; i++) {
            memset(a[i], false, n+2);
            Parent[i] = 0;
            IsCut[i] = false;
            nChildren[i] = false;
        }
        // Read Input
        gets(s);
        while (gets(s) && s[0]!='0') {
            int len = strlen(s), k = 0, u, v;
            while (k<len && s[k]==' ') k++;
            sscanf(s, "%d", &u);
//            printf("%d: ", u);
            while (k<len) {
                while (k<len && isdigit(s[k])) k++;
                while (k<len && s[k]==' ') k++;
                if (k<len) {
                    sscanf(s+k, "%d", &v);
//                    printf("%d ", v);
                    a[u][v] = a[v][u] = true;
                }
            }
 //           printf("\n");
        }
        // Visit
        Count = 0;
        for (int i=1; i<=n; i++)
            if (Parent[i]==0) {
                Parent[i] = -1;
                Visit(i);
            }
        // Result
        
        for (int v=1; v<=n; v++)
            if (Parent[v]!=-1) nChildren[Parent[v]]++;
        for (int v=1; v<=n; v++)
            if (Parent[v]!=-1) {
                int u = Parent[v];
                if (Low[v]>=Number[u]) {
                    IsCut[u] = IsCut[u] || (Parent[u]!=-1) || (nChildren[u]>=2);
                }
            }
        int nCut = 0;
        for (int v=1; v<=n; v++)
            if (IsCut[v]) nCut++;
        printf("%d\n", nCut);
    }
}

/* lamphanviet@gmail.com - 2011 */
