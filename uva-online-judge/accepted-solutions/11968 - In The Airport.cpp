//*****************
// LAM PHAN VIET **
// UVA 11968 - In The Airport
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 1005
#define INF 2100000000
int a[maxN], b[maxN];
int n, m, k;
double avg;

int Solve(int *ar, int nn) {
    int result= INF;
    double dis = INF;
    for (int i=1; i<=nn; i++) {
        double tmpdis = fabs(avg-double(ar[i]));
        if (tmpdis<dis || (tmpdis==dis && ar[i]<result)) {
            dis = tmpdis;
            result = ar[i];
        }
    }
    return result;
}

main() {
//   freopen("rr.inp", "r", stdin); freopen("rr.out", "w", stdout);
    int Case, val;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %d %d", &n, &m, &k);
        avg = 0.0;
        for (int i=1; i<=m; i++) {
            scanf("%d", &a[i]);
            avg += (double)a[i];
        }
        for (int i=1; i<=k; i++) {
            scanf("%d", &b[i]);
            avg += (double)b[i];
        }
        for (int i=m+k+1; i<=n; i++) {
            scanf("%d", &val);
            avg += (double)val;
        }
        avg /= n;
 //       printf("%lf\n", avg);
        sort(a+1, a+m+1); sort(b+1, b+k+1);
        
        int ans1 = Solve(a, m);
        int ans2 = Solve(b, k);
        
        printf("Case #%d: %d %d\n", kk, ans1, ans2);
    }
}

/* lamphanviet@gmail.com - 2011 */
