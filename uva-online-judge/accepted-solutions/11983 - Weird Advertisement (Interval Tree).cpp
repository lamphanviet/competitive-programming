/*****************/
/* LAM PHAN VIET */
/* UVA 11983 - Weird Advertisement
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
#define maxT 200000
#define maxN 70000
using namespace std;

struct Edge {
    int x, y1, y2;
    bool operator() (Edge a, Edge b) const {
        return a.x < b.x;
    }
};
int edges_size, k, tree[maxT], numbers[maxT];
Edge edges[maxN];
int points_size, points[maxN], ar[5];
char buff[100];

void read_line() {
    gets(buff);
    int len = strlen(buff), i = 0, n = 0;
    while (i < len)
        if (buff[i] != ' ') {
            int value = 0;
            while (i < len && buff[i] != ' ')
                value = value * 10 + buff[i++] - 48;
            ar[n++] = value;
        }
        else i++;
}

void readinput() {
    Edge e;
    int m, x;
    set<int> y_points;
    
    edges_size = 0;
    read_line();
    m = ar[0]; k = ar[1];
    while (m--) {
        read_line();
        e.x = ar[0]; e.y1 = ar[1]; x = ar[2]; e.y2 = ar[3];
        e.y2++;
        edges[edges_size++] = e;
        
        e.x = x + 1;
        swap(e.y1, e.y2);   // close tuong duong voi y1 > y2
        edges[edges_size++] = e;
        
        y_points.insert(e.y1);
        y_points.insert(e.y2);
    }
    sort(edges, edges + edges_size, Edge());
    
    points_size = 0;
    set<int>::iterator it = y_points.begin();
    while (it != y_points.end()) {
        points[points_size++] = *it;
        it++;
    }
}

void update(int p, int l, int r, int y1, int y2, int val, int pk) {
    if (y2 <= points[l] || points[r] <= y1) return;
    
    int child = p << 1, mid = (l + r) >> 1;
    
    if (y1 <= points[l] && points[r] <= y2) {
        numbers[p] += val;
        if (numbers[p] + pk >= k)
            tree[p] = points[r] - points[l];
        else {
            if (l + 1 == r) {
                tree[p] = 0;
                return;
            }
            update(child, l, mid, y1, y2, 0, numbers[p] + pk);
            update(child + 1, mid, r, y1, y2, 0, numbers[p] + pk);
            tree[p] = tree[child] + tree[child + 1];
        }
        return;
    }
    
    if (l + 1 == r) {
        if (numbers[p] + pk >= k)
            tree[p] = points[r] - points[l];
        else tree[p] = 0;
        return;
    }
    update(child, l, mid, y1, y2, val, numbers[p] + pk);
    update(child + 1, mid, r, y1, y2, val, numbers[p] + pk);
    if (numbers[p] + pk >= k)
        tree[p] = points[r] - points[l];
    else
        tree[p] = tree[child] + tree[child + 1];
}

int64 solve() {
    for (int i = 0, size_max = points_size * 3; i < size_max; i++)
        numbers[i] = tree[i] = 0;
        
    int64 area = 0;
    update(1, 0, points_size - 1, edges[0].y1, edges[0].y2, 1, 0);
    for (int i = 1; i < edges_size; i++) {
        area += tree[1] * (int64)(edges[i].x - edges[i-1].x);
        if (edges[i].y1 < edges[i].y2)
            update(1, 0, points_size - 1, edges[i].y1, edges[i].y2, 1, 0); // y1 y2
        else
            update(1, 0, points_size - 1, edges[i].y2, edges[i].y1, -1, 0);    // y2 y1
    }
    return area;
}

main() {
//    FileIn("test"); FileOut("test");
    read_line();
    int Case = ar[0];
    FOR (test, 1, Case) {
        readinput();
        printf("Case %d: %lld\n", test, solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
