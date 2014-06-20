//----------------------------
// LAM PHAN VIET
// UVA 11730 - Number Transformation
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

#define INF 1000
#define maxN 1005
#define maxP 505
int dp[maxN], s, t;
int prime[maxP], np = 0;
bool isPrime[maxP];

void Sieve() {
    memset(isPrime, true, maxP);
    for (int i=2; i*i<maxP; i++)
        if (isPrime[i]) {
            prime[np++] = i;
            for (int j=i*i; j<maxP; j+=i)
                isPrime[j] = false;
        }
    for (int i=prime[np-1]; i<=maxP; i++)
        if (isPrime[i]) prime[np++] = i;
}

main() {
    int kase = 0;
    Sieve();
    while (scanf("%d %d", &s, &t)) {
        if (!s && !t) break;
        printf("Case %d: ", ++kase);
        if (s==t) printf("0");
        else if (s>t) printf("-1");
        else {
            for (int i=s; i<=t; i++)
                dp[i] = INF;
            dp[s] = 0;
            for (int i=s; i<t; i++)
                if (dp[i]!=INF) {
                    for (int p=0; p<np && prime[p]<=i/2; p++)
                        if (i%prime[p]==0) {
                            int next = i+prime[p];
                            if (next<=t && dp[i]+1<dp[next])
                                dp[next] = dp[i]+1;
                        }
                }
            if (dp[t]==INF) printf("-1");
            else printf("%d", dp[t]);
        }
        printf("\n");
    }
}
