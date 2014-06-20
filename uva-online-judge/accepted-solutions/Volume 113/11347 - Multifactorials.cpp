//*****************
// LAM PHAN VIET **
// UVA 11347 - Multifactorials
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1002
#define ULL unsigned long long
bool isP[maxN];
int n, k, prime[170], np=0;
ULL INF;

void PreCal() {
    INF = 1000000000; INF *= INF;
    memset(isP, true, maxN);
    isP[0]=  isP[1] = false;
    For (i, 2, maxN-1)
        if (isP[i]) {
            prime[np++] = i;
            for (int j=i*i; j<maxN; j+=i)
                isP[j] = false;
        }
    For (i, prime[np-1]+1, maxN/2)
        if (isP[i]) prime[np++] = i;
}

ULL Solve() {
    int num[np], maxp=0;
    For (i, 0, np-1) num[i] = 0;
    
    while (n>1) {
        int m = n, p = 0;
        while (m>1) {
            if (m%prime[p]==0) {
                num[p]++;
                m /= prime[p];
                maxp = max(maxp, p);
            }
            else p++;
        }
        n-=k;
    }
    ULL ans = 1;
    For (i, 0, maxp)
        if (num[i]) {
            ans *= num[i]+1;
            if (ans>INF) return ans;
        }
    return ans;
}

main() {
//    freopen("347.inp", "r", stdin); freopen("347.out", "w", stdout);
    PreCal();
    int Case;
    char s[30];
    scanf("%d", &Case); gets(s);
    For (kk, 1, Case) {
        gets(s);
        sscanf(s, "%d", &n); k=0;
        for (int i=strlen(s)-1; i>=0; i--)
            if (s[i]=='!') k++;
            else break;
        ULL ans = Solve();
        printf("Case %d: ", kk);
        if (ans>INF) printf("Infinity\n");
        else printf("%lld\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
