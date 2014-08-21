//*****************
// LAM PHAN VIET **
// UVA 12004 - Bubble Sort
// Time limit: 1.000s
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define int64 long long
#define maxN 10000

main() {
 //   freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int Case; int64 n;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        scanf("%lld", &n);
        int64 ans = n*(n-1)/2;
        printf("Case %d: ", kk);
        if (ans%2) printf("%lld/2\n", ans);
        else printf("%lld\n", ans/2);
    }
}

/* lamphanviet@gmail.com - 2011 */
