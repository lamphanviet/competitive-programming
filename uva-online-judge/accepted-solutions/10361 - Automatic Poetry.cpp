//*****************
// LAM PHAN VIET **
// UVA 10361 - Automatic Poetry
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 111

main() {
//    freopen("361.inp", "r", stdin); freopen("361.out", "w", stdout);
    int Case, n, n2;
    char s[maxN], s2[maxN];
    scanf("%d", &Case); gets(s);
    while (Case--) {
        gets(s); n = strlen(s);
        for (int i=0; i<n; i++)
            if (s[i]!='<' && s[i]!='>') printf("%c", s[i]);
        printf("\n");
        
        gets(s2); n2 = strlen(s2);
        while (n2-1>=0 && s2[n2-1]=='.') n2--;
        s2[n2] = '\0';
        printf("%s", s2);
        
        int u = n-1, v;
        while (s[u]!='>') u--;
        v = n = u; n2 = 0;
        while (s[v]!='<') v--;
        For(i, v+1, u-1) s2[n2++] = s[i];
            
        u = v;
        while (s[v]!='>') v--;
        For(i, v+1, u-1) s2[n2++] = s[i];
        
        u = v;
        while (s[v]!='<') v--;
        For(i, v+1, u-1) s2[n2++] = s[i];
        
        s2[n2] = '\0';
        printf("%s", s2);
        
        puts(s+n+1);
    }
}

/* lamphanviet@gmail.com - 2011 */
