//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1204 - Weird Advertisement
// Time Limit   : 2.000s
// Description  : segment tree - rect
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 70000
#define maxT 200000
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Edge {
    int x, yMin, yMax, val;
    Edge() {}
    Edge(int xx, int y1, int y2, int v) {
        x = xx, val = v;
        yMin = y1, yMax = y2;
    }
    bool operator < (const Edge &e) const {
        return x < e.x;
	}
} edges[maxN];
int n, k, m, h[maxN], nedges;
int sum[maxT], counter[maxT];

void update(int p, int l, int r, int yMin, int yMax, int val, int up) {
    if (h[r] <= yMin || yMax <= h[l]) return;
    int c = p << 1, mid = (l + r) >> 1;
    if (yMin <= h[l] && h[r] <= yMax) {
        counter[p] += val;
        if (counter[p] + up >= k) sum[p] = h[r] - h[l];
        else {
			if (l + 1 >= r) {
				sum[p] = 0;
				return;
			}
			update(c, l, mid, yMin, yMax, 0, counter[p] + up);
			update(c + 1, mid, r, yMin, yMax, 0, counter[p] + up);
			sum[p] = sum[c] + sum[c + 1];
		}
		return;
    }
    if (l + 1 >= r) {
		if (counter[p] + up >= k)
			sum[p] = h[r] - h[l];
		else sum[p] = 0;
		return;
	}
    update(c, l, mid, yMin, yMax, val, up + counter[p]);
    update(c + 1, mid, r, yMin, yMax, val, up + counter[p]);
    if (counter[p] + up >= k) sum[p] = h[r] - h[l];
    else sum[p] = sum[c] + sum[c + 1];
}

int64 solve() {
    sort(h, h + m);
    int t = 1;
    FOR (i, 1, m - 1) if (h[i] != h[t - 1])
        h[t++] = h[i];
    m = t;
    for (int i = 0; i < maxT; i++)
        sum[i] = counter[i] = 0;
    sort(edges, edges + nedges);
    int64 area = 0LL;
    update(1, 0, m - 1, edges[0].yMin, edges[0].yMax, 1, 0);
    for (int i = 1; i < nedges; i++) {
        area += sum[1] * (int64)(edges[i].x - edges[i - 1].x);
        update(1, 0, m - 1, edges[i].yMin, edges[i].yMax, edges[i].val, 0);
    }
    return area;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, x1, y1, x2, y2;
    scanf("%d ", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &k);
        nedges = m = 0;
        REP(i, n) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x2++, y2++;
            edges[nedges++] = Edge(x1, y1, y2, 1);
            edges[nedges++] = Edge(x2, y1, y2, -1);
            h[m++] = y1;
            h[m++] = y2;
        }
        printf("Case %d: %lld\n", ++cases, solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
