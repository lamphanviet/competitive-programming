//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 300

int id[maxN][maxN], n, m[maxN];
vi child[10000];
char s[maxN][maxN], lab[10000];

void dfs(int u) {
    putchar(lab[u]);
    putchar('(');
    rep(i, child[u].size()) dfs(child[u][i]);
    child[u].clear();
    putchar(')');
}

const string ban = "-| #";
bool ok(char ch) {
    rep(i, ban.length())
        if (ch == ban[i]) return false;
    return true;
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases), gets(s[0]); cases--; ) {
        n = 0;
        while (gets(s[n]) && strcmp(s[n], "#") != 0) n++;
        int ver = 0;
        rep(i, n) m[i] = strlen(s[i]);
        rep(i, n) {
            rep(j, m[i]) {
                if (ok(s[i][j])) {
                    lab[ver] = s[i][j];
                    child[ver].clear();
                    if (i && s[i - 1][j] == '-')
                        child[id[i - 1][j]].pb(ver);
                    if (i + 2 < n && s[i + 1][j] == '|') {
                        int y = j;
                        while (y >= 0 && s[i + 2][y] == '-')
                            id[i + 2][y--]= ver;
                        y = j;
                        while (y < m[i + 2] && s[i + 2][y] == '-')
                            id[i + 2][y++]= ver;
                    }
                    ver++;
                }
            }
        }
        putchar('(');
        if (ver) dfs(0);
        putchar(')');
        puts("");
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
