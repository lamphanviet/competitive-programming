//----------------------------
// LAM PHAN VIET
// UVA 10323 - Factorial! You Must be Kidding!!!
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 15
typedef unsigned long long ULL;
ULL Fact[maxN];

main() {
    Fact[7] = 5040;
    for (ULL i=8; i<=13; i++)
        Fact[i] = Fact[i-1]*i;
    int n;
    while (scanf("%d", &n)!=EOF) {
        if (n>=0) {
            if (n<8) printf("Underflow!\n");
            else if (n>13) printf("Overflow!\n");
            else printf("%lld\n", Fact[n]);
        }
        else if (n%2) printf("Overflow!\n");
        else printf("Underflow!\n");
    }
}
