//----------------------------
// LAM PHAN VIET
// UVA 160 - Factors and Factorials
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 101
int prime[maxN], np=0;
bool isPrime[maxN];
int ans[maxN][30], maxpos[maxN];

void Sieve() {
    memset(isPrime, true, maxN);
    for (int i=2; i<maxN; i++)
        if (isPrime[i]) {
            for (int j=i*i; j<maxN; j+=i)
                isPrime[j] = false;
            prime[np++] = i;
        }
    for (int i=prime[np-1]+1; i<maxN; i++)
        if (isPrime[i]) prime[np++] = i;
}


void PreCal() {
    Sieve();
    for (int i=0; i<np; i++)
        ans[1][i] = 0;
    maxpos[1] = 0;
    for (int i=2; i<maxN; i++) {
        maxpos[i] = maxpos[i-1];
        for (int j=0; j<=maxpos[i]; j++)
            ans[i][j] = ans[i-1][j];
        int n = i, p = 0;
        while (n!=1) {
            if (n%prime[p]==0) {
                ans[i][p]++;
                n /= prime[p];
                maxpos[i] = max(maxpos[i], p);
            }
            else p++;
        }
    }
}


main() {
    int n;
    PreCal();
    while (scanf("%d", &n) && n) {
        printf("%3d! =", n);
        for (int i=0; i<=maxpos[n]; i++) {
            if (i%14==1 && i>1)
                printf("\n      ");
            printf("%3d", ans[n][i]);
        }
        printf("\n");
    }
}
