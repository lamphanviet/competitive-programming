/*****************/
/* LAM PHAN VIET */
/* UVA 481 - What Goes Up
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 100
using namespace std;

vector<int> a, b;

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v, i;
    
    while (scanf("%d",&m)!=EOF)
        a.push_back(m);
    
    vector<int> Trace(a.size());
    
    b.push_back(0);
    
    for (i=1; i<a.size(); i++) {
        if (a[i] > a[b.back()]) {
            Trace[i] = b.back();
            b.push_back(i);
            continue;
        }
        
        for (u=0, v = b.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (a[b[mid]] < a[i]) u = mid+1;
            else v = mid;
        }

        if (a[i] < a[b[u]]) {
            if (u>0) Trace[i] = b[u-1];
            b[u] = i;
        }
    }
    
    for (u = b.size(), v = b.back(); u--; v = Trace[v])
        b[u] = v;
    
    printf("%d\n", b.size());
    printf("-\n");
    u = b.back();
    REP(i, b.size())
        printf("%d\n", a[b[i]]);
}
