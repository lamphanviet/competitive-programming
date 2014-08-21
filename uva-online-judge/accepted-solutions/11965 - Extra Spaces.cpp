//*****************
// LAM PHAN VIET **
// UVA 11965 - Extra Spaces
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 505

main() {
 //   freopen("oo.inp", "r", stdin); freopen("oo.out", "w", stdout);
    int Case, n, m;
    char s[maxN];
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        printf("Case %d:\n", kk);
        
        scanf("%d", &m); gets(s);
        while (m--) {
            gets(s); n = strlen(s);
            if (n>0) printf("%c", s[0]);
            for (int i=1; i<n; i++)
                if (s[i]!=' ') printf("%c", s[i]);
                else if (s[i]!=s[i-1]) printf("%c", s[i]);
            printf("\n");
        }
        
        if (kk<Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
