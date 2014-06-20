/*****************/
/* LAM PHAN VIET */
/* UVa: 270 - Lining Up
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
#define Last(i) ( i & -i )
#define eps 1e-7
#define maxN 707
using namespace std;

class Point {
public:
    int x, y, vx, vy;
    void get_vector(Point p) {
        vx = x - p.x;
        vy = y - p.y;
        if (vy < 0)
            vx = -vx, vy = -vy;
        else if (vy == 0 && vx < 0)
            vx = -vx;
    }
    bool operator < (Point p) const {
        return (vx * p.vy > vy * p.vx);
    }
    bool operator == (Point p) const {
        return (vx * p.vy == vy * p.vx);
    }
} p[maxN];

int ar[5];
char buff[50];
bool read_line(Point &p) {
    if (!gets(buff)) return false;
    int len = strlen(buff), i = 0, m = 0;
    if (len == 0) return false;
    while (i < len)
        if (buff[i] != ' ')  {
            int sign = 1;
            ar[m] = 0;
            if (buff[i] == '-')
                sign = -1, i++;
            while (i < len && buff[i] != ' ')
                ar[m] = ar[m] * 10 + buff[i++] - 48;
            ar[m++] *= sign;
        }
        else i++;
    p.x = ar[0];
    p.y = ar[1];
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, n, result;
    for (scanf("%d ", &Case); Case--; ) {
        result = 1; n = 0;
        while (read_line(p[n])) n++;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++)
                p[j].get_vector(p[i]);
            sort(p + i + 1, p + n);
            int Count = 1;
            for (int j = i + 2; j < n; j++)
                if (p[j] == p[j - 1])
                    Count++;
                else {
                    result = max(result, Count + 1);
                    Count = 1;
                }
            result = max(result, Count + 1);
        }
        if (n == 0) result = 0;
        printf("%d\n", result);
        if (Case) putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
