//*****************
// LAM PHAN VIET **
// UVA 355 - The Bases Are Loaded
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
#define maxN 30
using namespace std;

char getDigit[] = "0123456789ABCDEF";
int a, b;
uint64 decml;
char s[maxN];

int Value(char ch) {
    if ('0'<=ch && ch<='9') return ch-48;
    else return ch - 'A' + 10;
}

bool Decimal() {
    int n = strlen(s);
    decml = 0;
    REP0 (i, n) {
        int k = Value(s[i]);
        if (k<0 || k>=a) return false;
        decml = decml*a + k;
    }
    return true;
}

void Convert() {
    int n = 0;
    while (decml) {
        s[n++] = getDigit[decml%b];
        decml /= b;
    }
    printf(" base %d = ", a);
    if (n==0) printf("0");
    else for (int i=n-1; i>=0; i--)
        printf("%c", s[i]);
    printf(" base %d\n", b);
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d %s", &a, &b, &s)!=EOF) {
        printf("%s", s);
        if (Decimal()) Convert();
        else printf(" is an illegal base %d number\n", a);
    }
}

/* lamphanviet@gmail.com - 2011 */
