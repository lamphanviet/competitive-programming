//----------------------------
// LAM PHAN VIET
// UVA 11609 - Teams
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 1000000007
typedef unsigned long long ULL;

ULL Pow2(int n) {
    if (n==0) return 1;
    if (n==1) return 2;
    ULL tmp = Pow2(n/2)%MOD;
    tmp = (tmp*tmp)%MOD;
    if (n%2==0) return tmp;
    return (tmp+tmp)%MOD;
}

main() {
    ULL Case, n;
    scanf("%lld", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%lld", &n);
        ULL ans = (n*Pow2(n-1))%MOD;
        printf("Case #%d: %lld\n", kk, ans);
    }
}
