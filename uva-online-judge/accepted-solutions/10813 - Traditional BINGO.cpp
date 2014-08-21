//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10813 - Traditional BINGO
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
#define maxN 10

const int n = 5, m = 75;
int a[maxN][maxN], b[100];
int row[maxN], col[maxN], d1[30], d2[30];
bool mark[maxN][maxN];

bool win(int x, int y) {
    mark[x][y] = true;
    if (++row[x] == 5) return true;
    if (++col[y] == 5) return true;
    if (++d1[x + y] == 5) return true;
    if (++d2[x - y + 5] == 5) return true;
    return false;
}

int solve() {
    row[2] = col[2] = 1;
    d1[2 + 2] = d2[2 - 2 + 5] = 1;
    rep(k, m)
        rep(i, n) rep(j, n)
            if (b[k] == a[i][j] && !mark[i][j]) {
                if (win(i, j)) return k + 1;
            }
    return 75;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases = 0;
    for (scanf("%d", &cases); cases--; ) {
        rep(i, n) rep(j, n) if (!(i == 2 && j == 2)) {
            scanf("%d", &a[i][j]);
        }
        a[2][2] = -100;
        rep(i, m) scanf("%d", &b[i]);
        fill(row, 0); fill(col, 0);
        fill(d1, 0); fill(d2, 0);
        fill(mark, false);
        printf("BINGO after %d numbers announced\n", solve());
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
