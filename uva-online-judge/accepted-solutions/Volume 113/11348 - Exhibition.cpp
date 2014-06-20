//*****************
// LAM PHAN VIET **
// UVA 11348 - Exhibition
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define N 10000
#define maxN 52
vector<int> cln[maxN];
int num[N+2], unq[maxN], n;

main() {
//    freopen("348.inp", "r", stdin); freopen("348.out", "w", stdout);
    int Case, m, stamp;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        for (int i=1; i<=N; i++) num[i] = 0;
        
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            cln[i].clear();
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &stamp);
                cln[i].push_back(stamp);
            }
            sort(cln[i].begin(), cln[i].end());
            int sizec = cln[i].size();
            if (sizec>0) num[cln[i][0]]++;
            for (int j=1; j<sizec; j++)
                if (cln[i][j]!=cln[i][j-1])
                    num[cln[i][j]]++;
        }
        
        int sum = 0;
        for (int i=0; i<n; i++) {
            unq[i] = 0;
            int sizec = cln[i].size();
            if (sizec>0 && num[cln[i][0]]==1) unq[i]++;
            for (int j=1; j<sizec; j++)
                if (cln[i][j]!=cln[i][j-1] && num[cln[i][j]]==1) unq[i]++;
            sum += unq[i];
        }
        
        printf("Case %d:", kk);
        for (int i=0; i<n; i++) {
            double percent = (double)unq[i]*100.0/(double)sum;
            printf(" %.6lf%%", percent);
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
