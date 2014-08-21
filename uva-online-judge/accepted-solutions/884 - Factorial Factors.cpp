//----------------------------
// LAM PHAN VIET
// UVA 884 - Factorial Factors
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define maxN 1000001
int ans[maxN];
bool isPrime[maxN];
vector<int> prime;

void Sieve() {
    memset(isPrime, true, maxN);
    isPrime[0] = isPrime[1] = false;
    for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
        if (isPrime[i]) {
            for (int j=i*i; j<=maxN; j+=i)
                isPrime[j] = false;
            prime.push_back(i);
        }
    for (int i=prime.back()+1; i<=maxN; i++)
        if (isPrime[i]) prime.push_back(i);
}

void PreCal() {
    Sieve();
    ans[1] = 0;
    for (int i=2; i<maxN; i++) {
        ans[i] = ans[i-1];
        int n=i, j=0;
        while (!isPrime[n]) {
            if (n%prime[j]==0) {
                ans[i]++;
                n /= prime[j];
            }
            else j++;
        }
        if (isPrime[n]) ans[i]++;
    }
}

main() {
    int n;
    PreCal();
    while (scanf("%d", &n)!=EOF)
        printf("%d\n", ans[n]);
}
