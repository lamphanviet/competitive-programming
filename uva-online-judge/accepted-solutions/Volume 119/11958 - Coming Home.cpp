//*****************
// LAM PHAN VIET **
// UVA 11958 - Coming Home
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 105
#define INF 1000000

bool cmp(int h1, int m1, int h2, int m2) {
    if (h1<h2) return true;
    if (h1==h2) return (m1<=m2);
    return false;
}

int Solve(int H, int M, int h1, int m1) {
//    printf("%d %d - %d %d\n", H, M, h1, m1);
    int tmp = (h1-H)*60;
    tmp += m1;
    tmp -= M;
    return tmp;
}

main() {
//    freopen("hh.inp", "r", stdin); freopen("hh.out", "w", stdout);
    int Case, n, H, M, h, m, K, ans;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %d:%d", &n, &H, &M);
//        printf("%d %d:%d\n", n, H, M);
        ans = INF;
        while (n--) {
            scanf("%d:%d %d", &h, &m, &K);
            int tmp;
            bool k = cmp(H, M, h, m);
            if (k) tmp = Solve(H, M, h, m);
            else tmp = 1440 - Solve(h, m, H, M);
            tmp += K;
            ans = min(ans, tmp);
        }
        printf("Case %d: %d\n", kk, ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
