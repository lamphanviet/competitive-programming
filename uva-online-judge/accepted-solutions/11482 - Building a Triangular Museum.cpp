//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11482 - Building a Triangular Museum
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

int n, m, mm;

char find(int i, int j, int lf, int rg) {
    if (j == lf) return '/';
    if (j == rg) return '\\';
    int r = (int)ceil(i / double(m));
    int k = rg - j;
    if (k % mm == 0 && k / mm <= r - 1) return '\\';
    
    k = j - lf;
    if (k % mm == 0 && k / mm <= r - 1) return '/';
    
    if (i % m == 0 && j > lf) return '_';
    return ' ';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int caseNo = 0;
    while (scanf("%d %d", &m, &n) && (n | m)) {
        mm = 2 * m;
        printf("Triangular Museum %d\n", ++caseNo);
        for (int i = 1, lf = m * n - 1, rg = m * n; i <= m * n; i++, lf--, rg++) {
            for (int j = 0; j < lf; j++) putchar(' ');
            for (int j = lf; j <= rg; j++)
                putchar(find(i, j, lf, rg));
            puts("");
        }
        puts("");
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
