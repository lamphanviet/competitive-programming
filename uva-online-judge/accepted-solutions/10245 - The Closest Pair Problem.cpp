/*****************/
/* LAM PHAN VIET */
/* UVa: 10245 - The Closest Pair Problem
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
#include <set>
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
#define maxN 10010
#define eps 1e-7
using namespace std;

class Point {
public:
    double x, y;
    Point() {}
    Point(double xx, double yy) { x = xx; y = yy; }
    bool operator < (const Point &p) const { return x < p.x; }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
} p[maxN];
class Height {
public:
    int pos;
    double y;
    Height() {}
    Height(double yy, int p) { y = yy; pos = p; }
    bool operator < (const Height &hei) const {
        return (y < hei.y || (y == hei.y && pos < hei.pos));
    }
};
int n;
set<Height> store;
set<Height>::iterator low, up, it;

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &n) && n) {
        double dist_min = 10001;
        FOR (i, 1, n)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p + 1, p + n + 1);
        store.clear();
        FOR (i, 1, n) {
            low = store.lower_bound(Height(p[i].y - dist_min, 0));
            up = store.upper_bound(Height(p[i].y + dist_min, n + 1));
    
            for (it = low; it != up; ) {
                dist_min = min(dist_min, p[i].dist(p[it->pos]));
                if (p[i].x - p[it->pos].x > dist_min)
                    store.erase(it++);
                else it++;
            }
    
            store.insert(Height(p[i].y, i));
        }
        if (dist_min < 10000.0)
            printf("%.4lf\n", dist_min);
        else puts("INFINITY");
    }
}

/* lamphanviet@gmail.com - 2011 */
