//*****************
// LAM PHAN VIET **
// UVA 11629 - Ballot evaluation
// Time limit: 1.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
#define maxN 10000
using namespace std;

int n, m;
map<string, int> Value;

void process_input() {
    int a, b;
    char s[30];
    while (n--) {
        scanf(" %s %d.%d ", &s, &a, &b);
        Value[s] = a * 10 + b;
    }
}

bool cmp(double a, string s, int b) {
    if (s == "=") return (a == b);
    if (s == "<=") return (a <= b);
    if (s == ">=") return (a >= b);
    if (s == "<") return (a < b);
    if (s == ">") return (a > b);
}

void solve_queries() {
    FOR (kk, 1, m) {
        int val = 0, res;
        char s[30];
        while (scanf(" %s ", &s)!=EOF) {
            if (s[0]=='=' || s[0]=='<' || s[0]=='>') {
                scanf(" %d ", &res);
                bool ans = cmp(val, s, res * 10);
                if (ans) printf("Guess #%d was correct.\n", kk);
                else printf("Guess #%d was incorrect.\n", kk);
                break;
            }
            if (s[0] != '+') val += Value[s];
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    scanf(" %d %d ", &n, &m);
    process_input();
    solve_queries();
}

/* lamphanviet@gmail.com - 2011 */
