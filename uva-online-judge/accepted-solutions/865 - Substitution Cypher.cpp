//*****************
// LAM PHAN VIET **
// UVA 865 - Substitution Cypher
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 128
char Sub[maxN], a[maxN], b[maxN];

main() {
    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int Case, len;
    scanf("%d", &Case); getchar(); getchar();
    while (Case--) {
        gets(a); gets(b);
        puts(b); puts(a);
        memset(Sub, 0, sizeof(Sub));
        For (i, 0, strlen(a)-1)
            Sub[a[i]] = b[i];
        while (gets(a)) {
            len = strlen(a);
            if (!len) break;
            For (i, 0, len-1)
                if (Sub[a[i]]==0) printf("%c", a[i]);
                else printf("%c", Sub[a[i]]);
            printf("\n");
        }
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
