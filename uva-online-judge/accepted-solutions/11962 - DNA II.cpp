//*****************
// LAM PHAN VIET **
// UVA 11962 - DNA II
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxS 35
typedef unsigned long long ULL;
int val[150];
char s[maxS];

main() {
 //   freopen("ll.inp", "r", stdin); freopen("ll.out", "w", stdout);
    val['A'] = 0; val['C'] = 1; val['G'] = 2; val['T'] = 3;
    int Case, n;
    scanf("%d", &Case); gets(s);
    for (int kk=1; kk<=Case; kk++) {
        gets(s); n = strlen(s);
        ULL ans = 0;
        for (int i=0; i<n; i++) {
            ans *= 4;
            ans += val[s[i]];
        }
        printf("Case %d: (%d:%lld)\n", kk, n, ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
