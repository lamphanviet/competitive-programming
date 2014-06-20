//*****************
// LAM PHAN VIET **
// UVA 12022 - Ordering T-shirts
// Time limit: 1.000s
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
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 15
using namespace std;

uint64 GT[maxN], ans[maxN];

void Cal(int n, int sum, int k, vector<int> a) {
    if (n==sum) {
        uint64 kq = GT[n];
        REP0 (i, a.size()) kq /= GT[a[i]];
        int dem = 1, x = a.size();
        uint64 add = 1;
        REP (i, 1, a.size()-1)
            if (a[i]==a[i-1]) dem++;
            else {
                add *= GT[x]/(GT[dem]*GT[x-dem]);
                x -= dem;
                dem = 1;
            }
        if (dem) add *= GT[x]/(GT[dem]*GT[x-dem]);
        ans[n] += kq*add;
        return;
    }
    REP (i, k+1, n) {
        if (sum + i > n) break;
        a.pb(i);
        Cal(n, sum+i, i, a);
        a.pop_back();
    }
    if (k==0) return;
    while (sum+k <=n) {
        sum += k;
        a.pb(k);
        Cal(n, sum, k+1, a);
    }
}

void PreCalc() {
    ans[1] = 1; ans[2] = 3;
    ans[3] = 13; ans[4] = 75;
    GT[0] = 1;
    REP (i, 1, 11) GT[i] = GT[i-1]*(uint64)i;
    REP (n, 1, 11) {
        ans[n] = 0;
        Cal(n, 0, 0, vector<int>());
    }
}

main() {
    FileIn("test"); FileOut("test");
    PreCalc();
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
