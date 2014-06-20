/*****************/
/* LAM PHAN VIET */
/* UVa: 11871 - New Land
/* Time limit: 5.000s
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
#define maxN 2002
using namespace std;

int n, m, h[maxN];
int f1[maxN], f2[maxN];
stack<int> S;

main() {
//    FileIn("test"); FileOut("test");
    int Case, area_max;
    scanf("%d", &Case);
    FOR (test, 1, Case) {
        area_max = 0;
        scanf("%d %d", &n, &m);
        FOR (i, 1, m) h[i] = 0;
        FOR (k, 1, n) {
            S = stack<int>();
            int i = 1, j = 1, t, val, p;
            
            scanf("%d %d", &t, &val);
            while (t--) {
                val = !val;
                scanf("%d", &p);
                while (p--) {
                    if (val) h[i]++;
                    else h[i] = 0;
                    
                    f1[i] = 1;
                    while (!S.empty() && h[S.top()] >= h[i])
                        j = S.top(), S.pop();
                    f1[i] = i - j + f1[j];
                    S.push(i);
                    
                    j = ++i;
                }
            }
            
            S = stack<int>();
            for (i = m, j = m; i >= 1; j = --i) {
                f2[i] = 1;
                while (!S.empty() && h[S.top()] >= h[i])
                    j = S.top(), S.pop();
                f2[i] = j - i + f2[j];
                S.push(i);
                
                area_max = max(area_max, (f1[i] + f2[i] - 1) * h[i]);
            }
        }
        printf("Case %d: %d\n", test, area_max);
    }
}

/* lamphanviet@gmail.com - 2011 */
