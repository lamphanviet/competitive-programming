//*****************
// LAM PHAN VIET **
// UVA 10295 - Hay Points
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
#define INF 500000000
#define maxN 20
using namespace std;

map<string, int> Value;

main() {
//    FileIn("test"); FileOut("test");
    int n, m, w;
    char s[maxN];
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf(" %s %d", &s, &w);
        Value[s] = w;
    }
    while (m--) {
        w = 0;
        while (scanf(" %s", &s)!=EOF) {
            if (s[0]=='.') break;
            w += Value[s];
        }
        printf("%d\n", w);
    }
}

/* lamphanviet@gmail.com - 2011 */
