//*****************
// LAM PHAN VIET **
// UVA 12027 - Very Big Perfect Squares
// Time limit: 1.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 1005
using namespace std;

char s[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%s", &s)!=EOF) {
        int n = strlen(s), k;
        if (n==1 && s[0]=='0') break;
        if (n%2) k = s[0]-48;
        else k = (int)(s[0]-48)*10 + (int)(s[1]-48);
        k = (int)sqrt(k);
        printf("%d", k);
        int s = 1;
        if (n%2==0) s++;
        n = (n-s)/2;
        REP0 (i, n) printf("0");
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
