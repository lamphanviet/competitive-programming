//*****************
// LAM PHAN VIET **
// UVA 195 - Anagram
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
#define maxN 100000
using namespace std;

bool cmp(char a, char b) {
    char aa = tolower(a), bb = tolower(b);
    if (aa == bb) return (a < b);
    return (aa < bb);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, n;
    char s[maxN];
    scanf("%d", &Case); gets(s);
    while (Case--) {
        gets(s);
        n = strlen(s);
        sort(s, s + n, cmp);
        do {
            puts(s);
        } while (next_permutation(s, s + n, cmp));
    }
}

/* lamphanviet@gmail.com - 2011 */
