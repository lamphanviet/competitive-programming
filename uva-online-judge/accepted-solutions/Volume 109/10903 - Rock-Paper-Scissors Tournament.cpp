//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10903 - Rock-Paper-Scissors Tournament
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
#define maxN 111

int n, m;
ii a[maxN];
map<string, int> idx;

int cmp(int x, int y) {
    if (x == y) return 0;
    bool sp = false;
    if (x > y) {
        swap(x, y); sp = true;
    }
    int res = 1;
    if (x == 1 && y == 2) res = -1;
    if (x == 2 && y == 3) res = -1;
    if (x == 3 && y == 1) res = -1;
    if (sp) res = 0 - res;
    return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	char s1[20], s2[20];
	int u, v, x, y;
	idx["rock"] = 1; idx["paper"] = 2; idx["scissors"] = 3;
	bool line = false;
	while (scanf(" %d ", &n)) {
        if (n == 0) break;
        scanf(" %d ", &m);
        m = m * ((n * (n- 1)) / 2);
        fr(i, 1, n) a[i].ff = a[i].ss = 0;
        while (m--) {
            scanf(" %d %s %d %s ", &u, s1, &v, s2);
            x = idx[s1]; y = idx[s2];
            int res = cmp(x, y);
            if (res == -1) {
                a[u].ss++; a[v].ff++;
            }
            else if (res == 1) {
                a[u].ff++; a[v].ss++;
            }
        }
        if (line) puts(""); line = true;
        fr(i, 1, n) {
            if (a[i].ff + a[i].ss == 0)
                puts("-");
            else printf("%.3lf\n", a[i].ff / (double)(a[i].ff + a[i].ss));
        }
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
