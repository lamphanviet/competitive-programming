//*****************
// LAM PHAN VIET **
// UVA 10507 - Waking up brain
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

int n, m, Count, Index[maxN];
bool cnt[maxN][maxN], wake[maxN];

int getIndex(char ch) {
    int idx = Index[ch - 65];
    if (!idx) idx = Index[ch - 65] = ++Count;
    return idx;
}

void initialize() {
    Fill(cnt, false);
    Fill(Index, 0);
    Fill(wake, false);
    Count = 0;
}

bool solve() {
    int res = 0;
    while (1) {
        vector<int> wake_list;
        FOR (i, 1, n)
            if (!wake[i]) {
                int adj_count = 0;
                FOR (j, 1, n)
                    if (cnt[i][j] && wake[j])
                        adj_count++;
                if (adj_count >= 3) wake_list.pb(i);
            }
            
        if (wake_list.size()) {
            res++;
            REP(i, wake_list.size())
                wake[wake_list[i]] = true;
            bool stop = true;
            for (int i = 1; i <= n && stop; i++)
                if (!wake[i]) stop = false;
            if (!stop) continue;
        }
        FOR (i, 1, n)
            if (!wake[i])return false;
        printf("WAKE UP IN, %d, YEARS\n", res);
        break;
    }
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int u, v;
    char s[maxN];
    while (scanf(" %d %d ", &n, &m)!=EOF) {
        initialize();
        scanf(" %s ", &s);
        REP(i, 3) {
            u = getIndex(s[i]);
            wake[u] = true;
        }
        while (m--) {
            scanf(" %s ", &s);
            u = getIndex(s[0]);
            v = getIndex(s[1]);
            cnt[u][v] = cnt[v][u] = true;
        }
        if (!solve()) puts("THIS BRAIN NEVER WAKES UP");
    }
}

/* lamphanviet@gmail.com - 2011 */
