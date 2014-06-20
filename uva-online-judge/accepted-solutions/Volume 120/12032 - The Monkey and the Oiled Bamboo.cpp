//*****************
// LAM PHAN VIET **
// UVA 12032 - The Monkey and the Oiled Bamboo
// Time limit:
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 100001
using namespace std;

int n, a[maxN];

bool Try(int k) {
    FOR (i, 1, n) {
        int dif = a[i] - a[i-1];
        if (dif==k) k--;
        else if (dif>k) return false;
    }
    return true;
}

int Solve() {
    int L = 1, R = 10000000, rs = 0;
    while (L<=R) {
        int mid = (L+R)/2;
        bool f = Try(mid);
        if (f) {
            rs = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    return rs;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d", &a[i]);
        a[0] = 0;
        printf("Case %d: %d\n", kk, Solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
