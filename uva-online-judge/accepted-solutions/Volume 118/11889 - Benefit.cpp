//----------------------------
// LAM PHAN VIET
// UVA 11889 - Benefit
// Time limit: 5s
//----------------------------
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int a, c;

int gcd(int n, int m) {
    if (n%m) return gcd(m, n%m);
    return m;
}

int Check() {
    if (c%a) return -1;
    for (int i=1; i<=a; i++)
        if (a%i==0 && gcd((c/a)*i, a)==i) return (c/a)*i;
}

main() {
    int Case, ans;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &a, &c);
        ans = Check();
        if (ans<0) puts("NO SOLUTION");
        else printf("%d\n", ans);
    }
}
