/*****************/
/* LAM PHAN VIET */
/* UVa: 10349 - Antenna Placement
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

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 410
using namespace std;

int r, c, idx[45][15];
int n, start, finish, new_base;
int T[maxN], b[maxN], match[maxN];
bool a[maxN][maxN], in_queue[maxN];
bool mark[maxN];
char s[45][15];
queue<int> Q;

void build_graph() {
    FOR (i, 1, n)
        FOR (j, 1, n)
            a[i][j] = false;
    REP(i, r)
        REP(j, c)
            if (idx[i][j]) {
                int u = idx[i][j], v;
                if (i + 1 < r && idx[i + 1][j]) {
                    v = idx[i + 1][j];
                    a[u][v] = a[v][u] = true;
                }
                if (j + 1 < c && idx[i][j + 1]) {
                    v = idx[i][j + 1];
                    a[u][v] = a[v][u] = true;
                }
            }
}

void init_bfs() {
    memset(in_queue, false, n + 1);
    in_queue[start] = true;
    Q = queue<int>();
    Q.push(start);
    
    memset(T, 0, (n + 1) * sizeof(int));
    FOR (i, 1, n) b[i] = i;
    finish = 0;
}

// blossom_shrink - start

int find_common_ancestor(int p, int q) {
    bool in_path[n + 1];
    memset(in_path, false, n + 1);
    while (1) {
        p = b[p];
        in_path[p] = true;
        if (p == start) break;
        p = T[match[p]];
    }
    while (1) {
        q = b[q];
        if (in_path[q]) break;
        q = T[match[q]];
    }
    return q;
}

void reset_trace(int x) {
    int u, v = x;
    while (b[v] != new_base) {
        u = match[v];
        mark[b[v]] = true;
        mark[b[u]] = true;
        v = T[u];
        if (b[v] != new_base) T[v] = u;
    }
}

void blossom_shrink(int p, int q) {
    memset(mark, false, n + 1);
    new_base = find_common_ancestor(p, q);
    reset_trace(p); reset_trace(q);
    if (b[p] != new_base) T[p] = q;
    if (b[q] != new_base) T[q] = p;
    FOR (i, 1, n)
        if (mark[b[i]]) b[i] = new_base;
    FOR (i, 1, n)
        if (!in_queue[i] && b[i] == new_base) {
            Q.push(i);
            in_queue[i] = true;
        }
}

// blossom_shrink - end

void find_augmenting_path() {
    init_bfs();
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n)
            if (a[u][v] && match[u] != v && b[u] != b[v]) {
                if ((v == start || match[v]) &&  T[match[v]])
                    blossom_shrink(u, v);
                else if (!T[v]) {
                    if (!match[v]) {
                        T[v] = u;
                        finish = v;
                        return;
                    }
                    else {
                        T[v] = u;
                        Q.push(match[v]);
                        in_queue[match[v]] = true;
                    }
                }
            }
    }
}

void enlarge() {
    int next, v;
    while (finish) {
        v = T[finish];
        next = match[v];
        match[v] = finish;
        match[finish] = v;
        finish = next;
    }
}

void solve() {
    memset(match, 0, (n + 1) * sizeof(int));
    FOR (u, 1, n)
        if (!match[u]) {
            start = u;
            find_augmenting_path();
            if (finish) enlarge();
        }
        
    int Count = 0;
    FOR (u, 1, n)
        if (match[u] > u)
            Count++;
    printf("%d\n", n - Count);
}

main() {
 //   InpFile("test.inp"); OutFile("test.out");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d ", &r, &c);
        n = 0;
        REP(i, r) {
            gets(s[i]);
            REP(j, c)
                idx[i][j] = (s[i][j] == '*') ? ++n : 0;
        }
        build_graph();
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
