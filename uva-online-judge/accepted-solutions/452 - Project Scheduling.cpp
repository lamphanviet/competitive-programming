/*****************/
/* LAM PHAN VIET */
/* UVA 452 - Project Scheduling
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 30
using namespace std;

int n, work_time[maxN], Index[maxN];
bool cnt[maxN][maxN], flag[maxN];
vector<int> sortedNode;
int dp[maxN];

void initialize() {
    Fill(cnt, false);
    Fill(flag, true);
    sortedNode.clear();
    REP(i, maxN) {
        dp[i] = work_time[i] = 0;
        Index[i] = -1;
    }
    n = 0;
}

void dfs(int u) {
    flag[u] = false;
    REP(v, n)
        if (flag[v] && cnt[u][v]) dfs(v);
    sortedNode.pb(u);
}

int getIndex(char ch) {
    int idx = Index[ch - 'A'];
    if (idx < 0) idx = Index[ch - 'A'] = n++;
    return idx;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, u, v, t;
    char s1[50], s2[50], ch;
    for (scanf("%d ", &Case); Case--; ) {
        initialize();
        while (gets(s1)) {
            if (!strlen(s1)) break;
            strcpy(s2, "");
            sscanf(s1, " %c %d %s ", &ch, &t, &s2);
            u = getIndex(ch);
            work_time[u] = t;
            t = strlen(s2);
            REP(i, t) {
                v = getIndex(s2[i]);
                cnt[u][v] = true;
                
            }
        }
        REP(i, n)
            if (flag[i]) dfs(i);
        int res = 0;
        REP(i, sortedNode.size()) {
            u = sortedNode[i];
            dp[u] = 0;
            REP(v, n)
                if (cnt[u][v])
                    dp[u] = max(dp[u], dp[v]);
            dp[u] += work_time[u];
            res = max(dp[u], res);
        }
        printf("%d\n", res);
        if (Case) puts("");
    }
}

/* lamphanviet@gmail.com - 2011 */
