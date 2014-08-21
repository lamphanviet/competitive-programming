//*****************
// LAM PHAN VIET **
// UVA 11344 - The Huge One
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 1005
int len, n;
char s[maxN];

bool Check(int n) {
    int du = 0;
    for (int i=0; i<len; i++) {
        du = du*10 + s[i]-48;
        du %= n;
    }
    return (du==0);
}

main() {
//    freopen("344.inp", "r", stdin); freopen("344.out", "w", stdout);
    int Case, a;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%s", &s); len =  strlen(s);
        bool wdf = true;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a);
            if (wdf) wdf = Check(a);
        }
        printf("%s - ", s);
        if (wdf) puts("Wonderful.");
        else puts("Simple.");
    }
}

/* lamphanviet@gmail.com - 2011 */
