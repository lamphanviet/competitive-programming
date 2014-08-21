//*****************
// LAM PHAN VIET **
// UVA 435 - Block Voting
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 22
#define maxM 20002
using namespace std;

int n, m, a[maxN];
int majority, power_index[maxN];
int sum[maxM], flag[maxM][maxN];

void initialize() {
    majority = m / 2 + 1;
    FOR (i, 0, n) power_index[i] = 0;
    FOR (i, 0, m) {
        Fill(flag[i], 0);
        sum[i] = 0;
    }
    sum[0] = 1;
}

void solve() {
    sum[a[1]] = 1;
    flag[a[1]][1] = 1;
    if (a[1] >= majority) power_index[1]++;
    FOR (i, 2, n) {
        for (int j = m; j >= 0; j--)
            if (sum[j]) {
                int next = j + a[i];
                if (next >= majority) {
                    if (j < majority)
                        power_index[i] += sum[j];
                    FOR (k, 1, n)
                        if (flag[j][k] && next - a[k] < majority)
                            power_index[k] += flag[j][k];
                }
                
                sum[next] += sum[j];
                FOR (k, 1, n)
                    flag[next][k] += flag[j][k];
                flag[next][i] += sum[j];
            }
    }
    
/*    printf("    "); FOR (i, 0, m) printf("%4d", i); puts("");
    printf("    "); FOR (i, 0, m) printf("%4d", sum[i]); puts("");
    FOR (i, 1, n) {
        printf("%4d", i);
        FOR (j, 0, m)
            printf("%4d", flag[j][i]);
        puts("");
    }
    puts("");   */
    
    FOR (i, 1, n)
        printf("party %d has power index %d\n", i, power_index[i]);
    printf("\n");
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        m = 0;
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            m += a[i];
        }
        initialize();
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
