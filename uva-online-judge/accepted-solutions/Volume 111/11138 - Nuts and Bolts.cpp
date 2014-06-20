/*****************/
/* LAM PHAN VIET */
/* UVa: 11138 - Nuts and Bolts
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
#define maxN 505
using namespace std;

int n, m, matchX[maxN], matchY[maxN];
int dist[maxN];
vector<int> adj[maxN];

bool bfs() {
    queue<int> Q;
    FOR (i, 1, n)
        if (!matchX[i]) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    dist[0] = INF;
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        REP(k, adj[i].size()) {
            int j = adj[i][k];
            if (dist[matchY[j]] == INF) {
                dist[matchY[j]] = dist[i] + 1;
                Q.push(matchY[j]);
            }
        }
    }
    return dist[0] != INF;
}

bool dfs(int i) {
    if (!i) return true;
    REP(k, adj[i].size()) {
        int j = adj[i][k];
        if (dist[matchY[j]] == dist[i] + 1 && dfs(matchY[j])) {
            matchX[i] = j;
            matchY[j] = i;
            return true;
        }
    }
    dist[i] = INF;
    return false;
}

int hopcroft_karp() {
    bool cont = false;
    FOR (i, 1, n)
        if (adj[i].size()) {
            cont = true;
            break;
        }
    if (!cont) return 0;
    memset(matchX, 0, (n + 1) * sizeof(int));
    memset(matchY, 0, (m + 1) * sizeof(int));
    int matching = 0;
    while (bfs())
        FOR (i, 1, n)
            if (!matchX[i] && dfs(i))
                ++matching;
    return matching;
}

int ar[3];
char buff[maxN * 5];
void read_line() {
    gets(buff);
    int len = strlen(buff), i = 0, m = 0;
    while (i < len)
        if (buff[i] != ' ') {
            ar[m] = 0;
            while (i < len && buff[i] != ' ')
                ar[m] = ar[m] * 10 + buff[i++] - 48;
            m++;
        }
        else i++;
}
void print(int n) {
    if (!n) {
        putchar('0');
        return;
    }
    int m = 0;
    while (n) {
        buff[m++] = n % 10 + 48;
        n /= 10;
    }
    while (m) putchar(buff[--m]);
}
void print_str(char *s) {
    int length = strlen(s);
    REP(i, length) putchar(s[i]);
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    int Case, k;
    read_line(); Case = ar[0];
    FOR (test, 1, Case) {
        read_line();
        n = ar[0], m = ar[1];
        FOR (i, 1, n) {
            adj[i].clear();
            gets(buff);
            for (int j = 1, k = 0; j <= m; j++, k += 2)
                if (buff[k] == '1')
                    adj[i].pb(j);
        }
        
        print_str("Case "); print(test);
        print_str(": a maximum of "); print(hopcroft_karp());
        print_str(" nuts and bolts can be fitted together");
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
