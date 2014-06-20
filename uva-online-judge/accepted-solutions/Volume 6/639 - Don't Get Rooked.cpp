//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 639 - Don't Get Rooked
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
#define maxN 7

const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { -1, 0, 0, 1 };
int n, res;
char s[maxN][maxN];
bool mark[maxN][maxN];

bool inside(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool canPlace(int x, int y) {
    if (s[x][y] == 'X') return false;
    rep(i, 4) {
        int xx = x, yy = y;
        while (inside(xx, yy)) {
            if (s[xx][yy] == 'X') break;
            if (mark[xx][yy]) return false;
            xx += dx[i]; yy += dy[i];
        }
    }
    return true;
}

void backTrack(int x, int y, int tmpRes) {
    if (y == n) { x++; y = 0; }
    
    res = max(res, tmpRes);
    if (x >= n) return;
    fr(i, x, n - 1) {
        fr(j, y, n - 1) {
            backTrack(i, j + 1, tmpRes);
            if (canPlace(i, j)) {
                mark[i][j] = true;
                backTrack(i, j + 1, tmpRes + 1); 
                mark[i][j] = false;
            }
        }
        y = 0;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d", &n) && n) {
        rep(i, n) scanf(" %s ", &s[i]);
        fill(mark, false);
        res = 0;
        backTrack(0, 0, 0);
        printf("%d\n", res);
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
