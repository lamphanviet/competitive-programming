//*****************
// LAM PHAN VIET **
// UVA 11970 - Lucky Numbers
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 31625
int dob[maxN], nd;

void PreCal() {
    nd = 0;
    for (int i=1; i<=maxN; i++)
        dob[nd++] = i*i;
}


main() {
//    freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
    PreCal();
    int Case, n, ans;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d", &n);
        printf("Case %d:", kk);
        for (int i=(int)sqrt(n); i>=1; i--) {
            int mau = i*i;
            if (mau>=n) continue;
            int x = n - mau;
            if (x%i==0) printf(" %d", x);
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
