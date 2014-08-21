//*****************
// LAM PHAN VIET **
// UVA 11221 - Magic square palindromes.
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10001
int n, k;
char s[maxN];

int CheckMagic() {
    k = (int)sqrt(n);
    if (k*k!=n) return -1;
    int i = 0, j = n-1;
    while (i<j) {
        if (s[i]!=s[j]) return -1;
        i++; j--;
    }
    return k;
}

main() {
 //   freopen("221.inp", "r", stdin); freopen("221.out", "w", stdout);
    int Case, len;
    scanf("%d", &Case); getchar();
    For (kk, 1, Case) {
        gets(s); len = strlen(s);
        n = 0;
        For (i, 0, len-1)
            if (isalpha(s[i])) s[n++] = s[i];
        s[n] = '\0';
        printf("Case #%d:\n", kk);
        int ans = CheckMagic();
        if (ans<0) puts("No magic :(");
        else printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
