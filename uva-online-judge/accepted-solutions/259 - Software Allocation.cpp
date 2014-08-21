//*****************
// LAM PHAN VIET **
// UVA 259 - Software Allocation
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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
#define INF 500000000
#define maxN 40
using namespace std;

const int s = 37, t = 38;
int n = 38, trace[maxN], sum_users;
int c[maxN][maxN], f[maxN][maxN];

bool find_path() {
    FOR (i, 1, n) trace[i] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n)
            if (!trace[v] && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v==t) return true;
                Q.push(v);
            }
    }
    return false;
}

void inc_flow() {
    int u, v, delta = INF;
    v = t;
    do {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    } while (v != s);
    v = t;
    do {
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    } while (v != s);
}

void initialize() {
    FOR (i, 1, n)
        FOR (j, 1, n)
            c[i][j] = f[i][j] = 0;
    sum_users = 0;
}

bool solve() {
    if (sum_users > 10) return false;
    while (find_path()) inc_flow();

    FOR (i, 1, 26)
        if (c[s][i]  && c[s][i] != f[s][i]) return false;
    FOR (v, 27, 36) {
        bool find = false;
        for (int u=1; u<=26 && !find; u++)
            if (f[u][v] > 0) {
                printf("%c", u + 'A' - 1);
                f[u][v]--;
                find =  true;
            }
        if (!find) printf("_");
    }
    printf("\n");
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    char str[maxN];
    int u, v, len, number_users;
    while (gets(str)) {
        initialize();
        do {
            len = strlen(str);
            if (!len) break;
            
            u = str[0] - 'A' + 1;
            number_users = str[1] - 48;
            sum_users += number_users;
            c[s][u] += number_users;
            int k = 3;
            while (k < len && str[k] != ';') {
                if ('0' <= str[k] && str[k] <= '9') {
                    v = str[k] - '0' + 27;
                    c[u][v] = 1;
                    c[v][t] = 1;
                }
                k++;
            }
        } while (gets(str));
        if (!solve()) puts("!");
    }
}

/* lamphanviet@gmail.com - 2011 */
