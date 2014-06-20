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
#define maxN 55

int size;
struct Matrix {
    unsigned int a[maxN][maxN];
    Matrix() {
        rep(i, size) rep(j, size) a[i][j] = 0;
    }
    Matrix multi(Matrix m) {
        Matrix res;
        rep(i, size) rep(j, size) rep(t, size)
            res.a[i][j] += a[i][t] * m.a[t][j];
        return res;
    }
} base;

Matrix power(Matrix mat, int64 p) {
    if (p == 1) return mat;
    Matrix res = power(mat, p / 2);
    res = res.multi(res);
    if (p % 2) return res.multi(mat);
    return res;
}

unsigned int c[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, maxN) {
	    c[i][0] = c[i][i] = 1;
	    fr(j, 1, i - 1)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	int64 n;
	int cases, caseNo = 0, k;
	for (scanf("%d", &cases); cases--; ) {
	    scanf(" %lld %d ", &n, &k); size = k + 2;
	    unsigned int res = 1;
	    if (n > 1) {
	        base = Matrix();
            fr(i, 0, k) fr(j, 0, i)
                base.a[i][j] = c[i][j];
            fr(j, 0, k) base.a[size - 1][j] = c[k][j];
            base.a[size - 1][size - 1] = 1;
            base = power(base, n - 1);
            res = 0;
            rep(j, size) res += base.a[size - 1][j];
	    }
	    printf("Case %d: %u\n", ++caseNo, res);
	}
	return 0;
}
