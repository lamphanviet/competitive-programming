//----------------------------
// LAM PHAN VIET
// UVA 10856 - Recover Factorial
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define maxF 2703665
#define maxN 10000001
int factor[maxF];
bool isPrime[maxF];
vector<int> prime;

void Sieve() {
    memset(isPrime, true, maxF);
    isPrime[0] = isPrime[1] = false;
    for (int i=2, lm=(int)sqrt(maxF); i<=lm; i++)
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j=i*i; j<maxF; j+=i)
                isPrime[j] = false;
        }
}

void PreCal() {
    Sieve();
    factor[0] = factor[1] = 0;
    for (int i=2; i<maxF; i++) {
        factor[i]=factor[i-1];
        int n = i, p = 0;
        while (isPrime[n]==false) {
            if (n%prime[p]==0) {
                factor[i]++;
                n = n/prime[p];
            }
            else p++;
        }
        factor[i]++;
    }
}

int Search(int val) {
    int u = 0, v = maxF;
    while (u<v) {
        int mid = (u+v)/2;
        if (factor[mid]==val) return mid;
        if (factor[mid]<val) u=mid+1;
        else if (factor[mid]>val) v=mid-1;
    }
    if (factor[v]==val) return v;
    return -1;
}

main() {
    PreCal();
    int Case=0, n, ans;
    while (scanf("%d", &n) && n>=0) {
        if (n==0) ans = 0;
        else ans = Search(n);
        printf("Case %d: ", ++Case);
        if (ans<0) printf("Not possible.\n");
        else printf("%d!\n", ans);
    }
}
