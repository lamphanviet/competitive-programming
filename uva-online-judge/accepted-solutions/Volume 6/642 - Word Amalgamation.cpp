//*****************
// LAM PHAN VIET **
// UVA 642 - Word Amalgamation
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
#define maxN 10
using namespace std;

map<string, int> Num;

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    while (gets(s)) {
        if (s[0]=='X') break;
        Num[s] = 1;
    }
    while (gets(s)) {
        if (s[0]=='X') break;
        bool f = false;
        int n = strlen(s);
        sort(s, s+n);
        do {
            if (Num[s]) puts(s), f = true;
        } while (next_permutation(s, s+n));
        if (!f) puts("NOT A VALID WORD");
        puts("******");
    }
}

/* lamphanviet@gmail.com - 2011 */
