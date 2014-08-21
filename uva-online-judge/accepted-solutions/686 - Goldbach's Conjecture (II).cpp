// 686 - Goldbach's Conjecture (II)
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define N 32768

using namespace std;

int prime[N], np;
bool isP[N+5];
int F[N+5];

void Sieve() {
    np = 0;
    memset(isP, true, N+3);
    isP[0] = isP[1] = false;
    for (int i=2; i<=N; i++)
        if (isP[i]) {
            prime[np++] = i;
            for (int j=i+i; j<=N; j+=i) isP[j] = false;
        }
}

void PreCal() {
    Sieve();
    memset(F, 0, N+5);
    for (int i=0; i<np; i++) {
        for (int j=i; j<np; j++) {
            int k = prime[i]+prime[j];
            if (k<=N) F[k]++;
        }
    }
}

main() {
    PreCal();
    int n;
    while (scanf("%d", &n)!=EOF && n) {
        printf("%d\n", F[n]);
    }
}
