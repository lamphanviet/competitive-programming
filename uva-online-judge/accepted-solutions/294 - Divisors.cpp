//*****************
// LAM PHAN VIET **
// UVA 294 - Divisors
// Time limit: 3.000s
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 31623

int CountDivisor(int n) {
    int Count = 2, k = (int)sqrt(n);
    for (int i=2; i<=k; i++)
        if (n%i==0) Count += 2;
    if (k*k==n) Count--;
    return Count;
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int Case, a, b;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &a, &b);
        int ans, Max = 0;
        For (i, a, b) {
            int k = CountDivisor(i);
            if (k>Max) {
                ans = i; Max = k;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, ans, Max);
    }
}

/* lamphanviet@gmail.com - 2011 */
