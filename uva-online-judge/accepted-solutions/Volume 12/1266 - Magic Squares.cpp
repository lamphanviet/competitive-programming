//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1266 - Magic Squares
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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 20

int n, a[maxN][maxN], val, lm;

void go(int x, int y) {
    a[x][y] = ++val;
    //printf("%d %d: %d\n", x, y, val);
    if (val == lm) return;
    int xx = x - 1, yy = y + 1;
    if (xx < 1) xx = n;
    if (yy > n) yy = 1;
    if (a[xx][yy] != 0) {
        go(x + 1, y);
    }
    else go(xx, yy);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	bool line = false;
	while (scanf("%d", &n) != EOF) {
	    if (line) puts(""); line = true;
	    lm = n * n;
	    printf("n=%d, sum=%d\n", n, ((n * n * (n * n + 1)) / 2) / n);
	    fr(i, 1, n) fr(j, 1, n) a[i][j] = 0;
	    val = 0;
	    go(1, 1 + n / 2); 
	    fr(i, 1, n) {
	        fr(j, 1, n) printf(" %d", a[i][j]);
	        puts("");
	    }
	}
	return 0;
}
