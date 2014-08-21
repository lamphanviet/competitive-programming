/*****************/
/* LAM PHAN VIET */
/* UVa: 11203 - Can you decide it for ME
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 60
using namespace std;

int n, a[5];
char s[maxN];

bool isTheorem() {
    int m = 0, i = 0;
    if (s[0] != '?') return false;
    a[m] = 1;
    while (++i < n)
        if (s[i] == '?') a[m]++;
        else {
            if (m == 0 && s[i] != 'M')
                return false;
            if (m == 1 && s[i] != 'E')
                return false;
            if (m == 2) return false;
            a[++m] = 0;
        }
    if (!a[1]) return false;
    return (a[2] - a[0] == a[1]);
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        n = strlen(s);
        if (!isTheorem()) printf("no-");
        puts("theorem");
    }
}

/* lamphanviet@gmail.com - 2011 */
