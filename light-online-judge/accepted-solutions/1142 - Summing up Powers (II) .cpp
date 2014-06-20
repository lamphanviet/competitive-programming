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
#define maxN 30
#define mod 10

int n, k;
struct Matrix {
    int a[30][30];
    Matrix() {
        rep(i, n) rep(j, n) a[i][j] = 0;
    }
    Matrix multi(Matrix m) {
        Matrix res;
        rep(i, n) rep(j, n) rep(k, n) {
            res.a[i][j] += a[i][k] * m.a[k][j];
            res.a[i][j] %= mod;
        }
        return res;
    }
    Matrix add(Matrix m) {
        Matrix res;
        rep(i, n) rep(j, n) {
            res.a[i][j] = a[i][j] + m.a[i][j];
            res.a[i][j] %= mod;
        }
        return res;
    }
} st, ZERO, ONE;
struct Mat {
    Matrix a[2][2];
    Mat() {
        rep(i, 2) rep(j, 2) a[i][j] = ZERO;
    }
    Mat multi(Mat m) {
        Mat res;
        rep(i, 2) rep(j, 2) rep(k, 2) {
            res.a[i][j] = res.a[i][j].add(a[i][k].multi(m.a[k][j]));
        }
        return res;
    }
} base;

Mat power(Mat N, int K) {
    if (K == 1) return N;
    Mat res = power(N, K / 2);
    res = res.multi(res);
    if (K % 2 == 1) return res.multi(N);
    return res;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, maxN) rep(j, maxN) {
	    ZERO.a[i][j] = 0;
	    ONE.a[i][j] = 0;
	    if (i == j) ONE.a[i][j] = 1;
	}
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d", &n, &k);
	    rep(i, n) rep(j, n) {
	        scanf("%d", &st.a[i][j]);
	        st.a[i][j] %= mod;
	    }
	    if (k >= 2) {
	        base.a[0][0] = st;
            base.a[0][1] = ONE;
            base.a[1][0] = Matrix();
            base.a[1][1] = ONE;
            base = power(base, k - 1);
            st = (base.a[0][0].add(base.a[0][1])).multi(st);
	    }
	    printf("Case %d:\n", ++caseNo);
	    rep(i, n) {
	        rep(j, n) printf("%d", st.a[i][j]);
	        puts("");
	    }
	}
	return 0;
}
