/*****************/
/* LAM PHAN VIET */
/* UVa: 11857 - Driving Range
/* Time limit: 5.000s
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
#define INF 500000000
#define maxN 1000001
using namespace std;

struct Edge {
    int u, v, w;
} e[maxN];
int n, m, lab[maxN];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int get_root(int v) {
    if (lab[v] < 0) return v;
    lab[v] = get_root(lab[v]);
    return lab[v];
}

void union_root(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] > lab[r2])
        lab[r1] = r2, lab[r2] = x;
    else
        lab[r1] = x, lab[r2] = r1;
}

void down_heap(int r) {
    Edge v = e[r];
    while ((r << 1) <= m) {
        int c = r << 1;
        if (c < m && e[c + 1].w < e[c].w) c++;
        if (e[c].w >= v.w) break;
        e[r] = e[c];
        r = c;
    }
    e[r] = v;
}

int kruskal() {
    sort(e + 1, e + m + 1, cmp);
    int result = 0, count_edge = 0;
    FOR (i, 1, m) {
        int r1 = get_root(e[i].u), r2 = get_root(e[i].v);
        if (r1 != r2) {
            union_root(r1, r2);
            result = max(result, e[i].w);
            if (++count_edge == n - 1) break;
        }
    }
    return count_edge == n - 1 ? result : -1;
}

int ar[5];
char buff[50];
bool read_line(Edge &e) {
    if (!gets(buff)) return false;
    int len = strlen(buff), i = 0, m = 0;
    while (i < len)
        if (buff[i] != ' ') {
            ar[m] = 0;
            while (i < len && buff[i] != ' ')
                ar[m] = ar[m] * 10 + buff[i++] - 48;
            m++;
        }
        else i++;
    e.u = ar[0], e.v = ar[1], e.w = ar[2];
    return true;
}

void print(int n) {
    if (!n) {
        putchar('0'); return;
    }
    int m = 0;
    while (n) {
        buff[m++] = n % 10 + 48;
        n /= 10;
    }
    while (m) putchar(buff[--m]);
}

main() {
 //   FileIn("test"); FileOut("test");
    char im[] = "IMPOSSIBLE";
    while (read_line(e[0]) && (ar[0] || ar[1])) {
        n = ar[0]; m = ar[1];
        FOR (i, 1, m) read_line(e[i]);
        REP(i, n) lab[i] = -1;
        int result = kruskal();
        if (result < 0) {
            REP(i, 10) putchar(im[i]);
            putchar('\n');
        }
        else {
            print(result);
            putchar('\n');
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
