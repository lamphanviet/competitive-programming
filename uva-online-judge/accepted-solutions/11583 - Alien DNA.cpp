//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11583 - Alien DNA
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
#define maxN 10111

int n, h[maxN][30], f[maxN];
char s[maxN];
bool flag[maxN][30];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int cases, m;
	for (scanf("%d ", &cases); cases--; ) {
        scanf(" %d ", &n);
        fr(i, 1, n) {
            scanf(" %s ", s);
            int len = strlen(s);
            fill(flag[i], false);
            rep(j, len) flag[i][s[j] - 'a'] = true;
        }
        fill(flag[0], false);
        fill(h[0], 0);
        f[0] = 0;
        fr(i, 1, n) {
            f[i] = INF;
            rep(j, 26) {
                if (flag[i][j]) h[i][j] = h[i - 1][j] + 1;
                else h[i][j] = 0;
                f[i] = min(f[i], f[i - h[i][j]] + 1);
            }
        }
       
        printf("%d\n", f[n] - 1);
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
