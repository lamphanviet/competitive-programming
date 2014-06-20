//----------------------------
// LAM PHAN VIET
// UVA 11415 - Count the Factorials
// Time limit: 5s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxF 2703665
int fact[maxF];

void PreCal() {
    for (int i=0; i<maxF; i++) fact[i] = 0;
    for (int i=2, lm=maxF/2; i<=lm; i++)
        if (fact[i]==0) {
            fact[i]++;
            for (int j=i+i; j<maxF; j+=i) {
                int n = j;
                while (n%i==0) {
                    fact[j]++;
                    n /= i;
                }
            }
        }
    fact[0] = fact[1] = 0;
    for (int i=2; i<maxF; i++) {
        if (fact[i]==0) fact[i]++;
        fact[i] += fact[i-1];
    }
}

int Search(int val) {
    int u=0, v=maxF-1;
    while (u<v) {
        int mid = (u+v)/2;
        if (fact[mid]<val) u=mid+1;
        else v = mid;
    }
    if (fact[u]<=val) return u+1;
    return u;
}

main() {
    PreCal();
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        printf("%d\n", Search(n));
    }
}
