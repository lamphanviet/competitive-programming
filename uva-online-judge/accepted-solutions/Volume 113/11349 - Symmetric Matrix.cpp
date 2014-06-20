//*****************
// LAM PHAN VIET **
// UVA 11349 - Symmetric Matrix
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 102
typedef long long LL;
LL a[maxN][maxN];
int n;

main() {
 //   freopen("349.inp", "r", stdin); freopen("349.out", "w", stdout);
    int Case; char tmp1, tmp2;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%c", &tmp1);  // dau xuong dong
        scanf("%c %c %d", &tmp1, &tmp2, &n);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                scanf("%lld", &a[i][j]);
        bool symetric = true;
        int u = 1, v = n;
        while (u<=v && symetric) {
            int i = 1, j = n;
            while (i<=n && symetric) {
                if (a[u][i]!=a[v][j]) symetric = false;
                if (a[u][i]<0 || a[v][j]<0) symetric = false;
                i++; j--;
            }
            u++; v--;
        }
        
        printf("Test #%d: ", kk);
        if (symetric) printf("Symmetric.");
        else printf("Non-symmetric.");
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
