//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1120 - Rectangle Union
// Time Limit   : 2.000s
// Description  : 
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
#define maxN 30010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int read(int &n){return scanf(" %d ",&n);}
int read(int64 &n){return scanf(" %lld ",&n);}
int read(uint64 &n){return scanf(" %llu ",&n);}
int read(double &n){return scanf(" %lf ",&n);}
int read(char *c){return scanf(" %s ",c);}

struct Edge {
    bool open;
    int x, yMin, yMax;
    Edge(int x, int y1, int y2, bool op) {
        this->x = x;
        yMin = y1, yMax = y2;
        open = op;
    }
    bool operator < (const Edge &e) const {
        return (x < e.x);
    }
};
int n, m, h[maxN << 1];
int sum[maxN << 5], counter[maxN << 5];
vector<Edge> edges;

void update(int p, int l, int r, int yMin, int yMax, bool open) {
    if (h[r] < yMin || yMax < h[l]) return;
    int c = p << 1, mid = (l + r) >> 1;
    if (yMin <= h[l] && h[r] <= yMax) {
        counter[p] += open ? 1 : -1;
        if (counter[p]) sum[p] = h[r] - h[l];
        else sum[p] = sum[c] + sum[c + 1];
        return;
    }
    if (l + 1 >= r) return;
    update(c, l, mid, yMin, yMax, open);
    update(c + 1, mid, r, yMin, yMax, open);
    if (counter[p]) sum[p] = h[r] - h[l];
    else sum[p] = sum[c] + sum[c + 1];
}

int64 solve() {
    // process height
    sort(h + 1, h + m + 1);
    int k = 1;
    FOR (i, 2, m) if (h[i] != h[k])
        h[++k] = h[i];
    m = k;
    // init tree
    for (int i = 0, lm = maxN << 4; i < lm; i++)
        sum[i] = 0, counter[i] = 0;
    // solve
    int64 area = 0LL;
    sort(all(edges));
    update(1, 1, m, edges[0].yMin, edges[0].yMax, edges[0].open);
    for (int i = 1; i < edges.size(); i++) {
        area += sum[1] * (int64)(edges[i].x - edges[i - 1].x);
        update(1, 1, m, edges[i].yMin, edges[i].yMax, edges[i].open);
    }
    return area;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, x1, y1, x2, y2;
    read(caseNo);
    while (caseNo--) {
        read(n);
        edges.clear();
        m = 0;
        FOR (i, 1, n) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            edges.pb(Edge(x1, y1, y2, true));
            edges.pb(Edge(x2, y1, y2, false));
            h[++m] = y1;
            h[++m] = y2;
        }
        printf("Case %d: %lld\n", ++cases, solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
