//----------------------------
// LAM PHAN VIET
// UVA 11401 - Triangle Counting
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 1000000
typedef unsigned long long ULL;
ULL ans[maxN+5];

void PreCal() {
    ans[3] = 0;
    for (int n=4; n<=maxN; n++) {
        ans[n] = ans[n-1];
        ULL k = (n+1)/2;
        ans[n] += (k-1)*((ULL)n-k-1);
    }
}

main() {
    PreCal();
    int n;
    while (scanf("%d", &n) && n>=3) {
        printf("%lld\n", ans[n]);
    }
}
