/*****************/
/* LAM PHAN VIET */
/* UVa: 12048 - Inhabitants
/* Time limit: 1.000s
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
#define eps 1e-10
#define maxN 100010
using namespace std;

class Point {
public:
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
    double dist(Point p) {
        int64 dx, dy;
        dx = x - p.x; dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};
int n;
Point p[maxN];

int64 area(Point a, Point b, Point c) {
    int64 s = (a.x - b.x) * (int64)(a.y + b.y);
    s += (b.x - c.x) * (int64)(b.y + c.y);
    s += (c.x - a.x) * (int64)(c.y + a.y);
    return (s > 0) ? s : -s;
}

int ccw(Point p1, Point p2, Point p3) {
    int64 a1, b1, a2, b2, t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (t == 0) return 0;
    return (t > 0) ? -1: 1;
}

bool is_on_seg(Point p, Point a, Point b) {
    return fabs(p.dist(a) + p.dist(b) - a.dist(b)) < eps;
}

bool check(Point p0) {
    int L = 1, R = n - 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        int turn = ccw(p[0], p[mid], p0);
        if (turn < 0)
            L = mid + 1;
        else if (turn > 0)
            R = mid;
        else
            return is_on_seg(p0, p[0], p[mid]);
    }
    int64 s0 = area(p[0], p[R - 1], p[R]);
    int64 s1 = area(p0, p[R], p[R - 1]) + area(p0, p[0], p[R]) + area(p0, p[0], p[R - 1]);
    if (s0) return (s0 == s1);
    return is_on_seg(p0, p[R], p[0]) || is_on_seg(p0, p[0], p[R - 1]) || is_on_seg(p0, p[R - 1], p[R]);
}

int ar[5];
char buff[50];
void read_line() {
    gets(buff);
    int len = strlen(buff), i = 0, m = 0;
    while (i < len)
        if (buff[i] != ' ') {
            int sign = 1;
            if (buff[i] == '-')
                sign = -1, i++;
            ar[m] = 0;
            while (i < len && buff[i] != ' ')
                ar[m] = ar[m] * 10 + buff[i++] - 48;
            ar[m++] *= sign;
        }
        else i++;
}

void read_polygon() {
    int start = 0, m = 0;
    scanf("%d ", &n);
    Point p1[n];
    REP(i, n) {
        read_line();
        p1[i].x = ar[0]; p1[i].y = ar[1];
        if (p1[i].y < p1[start].y || (p1[i].y == p1[start].y && p1[i].x < p1[start].x))
            start = i;
    }
    p[m++] = p1[start];
    for (int i = (start + 1) % n; i != start; i = (i + 1) % n)
        if (m <= 1 || ccw(p[m - 2], p[m - 1], p1[i]))
            p[m++] = p1[i];
        else p[m - 1] = p1[i];
    if (m >= 3 && !ccw(p[m - 2], p[m - 1], p[0])) m--;
    n = m;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, x, y;
    for (scanf("%d", &Case); Case--; ) {
        read_polygon();
        scanf("%d ", &m);
        while (m--) {
            read_line();
            if (check(Point(ar[0], ar[1]))) putchar('y');
            else putchar('n');
            putchar('\n');
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
