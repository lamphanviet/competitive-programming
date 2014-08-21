//*****************
// LAM PHAN VIET **
// UVA 11960 - Divisor Game
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 1000000
int dp[N+3], numdv[N+3];

void PreCal() {
    for (int i=0; i<=N; i++) {
        numdv[i] = 1;
    }
    for (int i=2; i<=N; i++) {
        numdv[i]++;
        for (int j=i+i; j<=N; j+=i)
            numdv[j]++;
    }
    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        if (numdv[i]>=numdv[dp[i-1]])
            dp[i] = i;
        else dp[i] = dp[i-1];
    }
}

main() {
    PreCal();
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
