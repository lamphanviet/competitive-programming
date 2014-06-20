//*****************
// LAM PHAN VIET **
// UVA 10720 - Graph Construction
// Time limit: 3.000
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
#define maxN 10001
using namespace std;

int n, deg[maxN];
int sum, left_sum[maxN];
bool valid;

bool cmp(int a, int b) { return a > b; }

int search(int L, int R, int k) {
    int rs = L - 1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (deg[mid] >= k) {
            rs = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return rs;
}

bool solve() {
    if (!valid) return false;
    if (sum & 1) return false;
    sort(deg + 1, deg + n + 1, cmp);
    left_sum[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        left_sum[i] = left_sum[i + 1] + deg[i];
    int left = 0, right;
    FOR (k, 1, n) {
        int p = search(k + 1, n, k);
        left += deg[k];
        right = k * (p - 1) + left_sum[p + 1];
        if (left > right) return false;
    }
    return true;
}

main() {
 //   FileIn("test"); FileOut("test");
    while (scanf("%d", &n) && n) {
        valid = true;
        sum = 0;
        FOR (i, 1, n) {
            scanf("%d", &deg[i]);
            if (!valid) continue;
            if (deg[i] >= n || deg[i] < 0) valid = false;
            sum += deg[i];
        }
        if (solve()) puts("Possible");
        else puts("Not possible");
    }
}

/* lamphanviet@gmail.com - 2011 */
