//----------------------------
// LAM PHAN VIET
// UVA 11407 - Squares
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 10005
#define N 10000
#define INF 1000000
int pow2[105], dp[maxN];

void PreCal() {
    for (int i=1; i<=100; i++)
        pow2[i] = i*i;
    for (int i=1; i<=N; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i=0; i<=N; i++)
        for (int j=1; j<=100; j++) {
            int u = pow2[j]+i;
            if (u>N) break;
            if (dp[i]+1<dp[u]) dp[u] = dp[i]+1;
        }
}

main() {
    int Case, n;
    PreCal();
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}
