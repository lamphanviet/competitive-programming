//----------------------------
// LAM PHAN VIET
// UVA 568 - Just the Facts
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 10001
int ans[maxN];

void PreCal() {
    ans[0] = 1;
    for (int n=1; n<maxN; n++) {
        ans[n] = ans[n-1]*n;
        while (ans[n]%10==0) ans[n] /= 10;
        ans[n] %= 100000;
    }
}

main() {
    int n;
    PreCal();
    while (scanf("%d", &n)!=EOF)
        printf("%5d -> %d\n", n, ans[n]%10);
}
