//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1032 - Fast Bit Calculations 
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

#define BIT(n) (1LL<<(n))
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
#define maxN 32

int64 f[maxN][2];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    f[0][0] = f[0][1] = 0;
    fr(i, 1, maxN - 1) {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i][0] + BIT(i - 1);
    }
    int cases, caseNo = 0, n;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d", &n);
        int hi = 0;
        rep(i, maxN) hi = (n & BIT(i)) ? i : hi;
        int64 res = f[hi][0] + f[hi][1];
        bool prev = true, cur;
        int lost = 0;
        frr(i, hi - 1, 0) {
            cur = n & BIT(i);
            if (prev && cur) lost++;
            if (!cur) {
                res -= f[i][1];
                res -= lost * BIT(i);
                if (prev) res -= BIT(i);
            }
            prev = cur;
        }
        printf("Case %d: %lld\n", ++caseNo, res);
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
