//*****************
// LAM PHAN VIET **
// UVA 389 - Basically Speaking
// Time limit: 3.000s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 100
using namespace std;

uint64 a, b;
char s[maxN];

int Value(char ch) {
    if ('0' <= ch && ch <= '9') return (ch-48);
    else return (ch-55);
}

char Char(int val) {
    if (0 <= val && val <=9) return (val+48);
    else return (val+55);
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf(" %s %d %d", &s, &a, &b)!=EOF) {
        uint64 rs = 0;
        for (int i=0, len=strlen(s); i<len; i++)
            rs = rs*a + Value(s[i]);
        int len = 0;
        while (rs) {
            s[len++] = Char(rs%b);
            rs /= b;
        }
        if (len>7) puts("  ERROR");
        else {
            if (len==0) s[len++] = '0';
            FOR (i, len, 6) printf(" ");
            for (int i=len-1; i>=0; i--) printf("%c", s[i]);
            printf("\n");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
