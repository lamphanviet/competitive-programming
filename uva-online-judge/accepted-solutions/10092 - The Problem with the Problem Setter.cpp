/*****************/
/* LAM PHAN VIET */
/* UVa: 10092 - The Problem with the Problem Setter
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
#define maxN 1001
#define maxM 110
using namespace std;

int ar[maxM];
char buff[maxM * 10];
void read_array() {
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

int n, m, mm, matchX[maxN], matchY[maxM];
int range[maxM], dist[maxN];
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
        REP(k, adj[i].size())
            FORR (j, range[adj[i][k]], range[adj[i][k] + 1])
                if (dist[matchY[j]] == INF) {
                    dist[matchY[j]] = dist[i] + 1;
                    Q.push(matchY[j]);
                }
    }
    return (dist[0] != INF);
}

bool dfs(int i) {
    if (!i) return true;
    REP(k, adj[i].size()) {
        FORR (j, range[adj[i][k]], range[adj[i][k] + 1]) {
            if (dist[matchY[j]] == dist[i] + 1 && dfs(matchY[j])) {
                matchX[i] = j;
                matchY[j] = i;
                return true;
            }
        }
    }
    dist[i] = INF;
    return false;
}

void hopcroft_karp() {
    memset(matchX, 0, (n + 1) * sizeof(int));
    memset(matchY, 0, (m + 1) * sizeof(int));
    while (bfs())
        FOR (i, 1, n)
            if (!matchX[i]) dfs(i);
}

void result() {
    FOR (j, 1, m)
        if (!matchY[j]) {
            puts("0");
            return;
        }
    puts("1");
    FOR (i, 1, mm) {
        printf("%d", matchY[range[i]]);
        FORR (j, range[i] + 1, range[i + 1]) {
            printf(" %d", matchY[j]);
        }
        putchar('\n');
    }
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    int k;
    while (scanf(" %d %d ", &mm, &n) && (mm || n)) {
        read_array();
        range[1] = 1;
        FOR (i, 1, mm)
            range[i + 1] = range[i] + ar[i - 1];
        m = range[mm + 1] - 1;
        FOR (i, 1, n) {
            read_array();
            adj[i].resize(ar[0]);
            REP(j, ar[0])
               adj[i][j] = ar[j + 1];
        }
        hopcroft_karp();
        result();
    }
}

/* lamphanviet@gmail.com - 2011 */
