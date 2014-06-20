//*****************
// LAM PHAN VIET **
// UVA 599 - The Forrest for the Trees
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
#define maxN 30
using namespace std;

int Lab[maxN];

int GetRoot(int v) {
    if (Lab[v] < 0) return v;
    Lab[v] = GetRoot(Lab[v]);
    return Lab[v];
}

void Union(int r1, int r2) {
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

main() {
    FileIn("test"); FileOut("test");
    int Case, u, v;
    char s[100];
    scanf("%d", &Case); scanf(" ");
    while (Case--) {
        FOR (i, 1, 26) Lab[i] = -1;
        while (gets(s)) {
            if (s[0]=='*') break;
            u = s[1]-64; v = s[3] - 64;
            u = GetRoot(u); v = GetRoot(v);
            if (u!=v) Union(u, v);
        }
        gets(s); int len = strlen(s);
        int tree = 0, corn = 0;
        for (int i=0; i<len; i+=2) {
            int u = s[i] - 64;
            if (Lab[u]==-1) corn++;
            else if (Lab[u]<0) tree++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, corn);
    }
}

/* lamphanviet@gmail.com - 2011 */
