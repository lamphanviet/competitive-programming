//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1160 - Discovering Paths in Grid 
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
#define maxN 100111
#define mod 1000000007

const int size = 35;
struct Matrix {
    int a[size][size];
    Matrix() {
        rep(i, size) rep(j, size) a[i][j] = 0;
    }
    Matrix multi(Matrix mat) {
        Matrix res;
        rep(i, size) rep(j, size) rep(k, size) {
            res.a[i][j] += (a[i][k] * (int64)mat.a[k][j]) % mod;
            res.a[i][j] %= mod;
        }
        return res;
    }
} base;

Matrix power(Matrix mat, int k) {
    if (k == 1) return mat;
    Matrix res = power(mat, k / 2);
    res = res.multi(res);
    if (k % 2) return res.multi(mat);
    return res;
}

bool cnt(vi a, vi b) {
    do {
        bool ok = true;
        rep(i, 4) if (abs(a[i] - b[i]) != 1) {
            ok = false;
            break;
        }
        if (ok) return true;
    } while (next_permutation(all(b)));
    return false;
}

vector<vi> stat;

void init() {
    rep(i, 7) fr(j, i + 1, 6) fr(u, j + 1, 6) fr(v, u + 1, 6) {
        vi tmp;
        tmp.pb(i); tmp.pb(j); tmp.pb(u); tmp.pb(v);
        stat.pb(tmp);
    }
    base = Matrix();
    rep(i, stat.size()) rep(j, stat.size())
        base.a[i][j] = cnt(stat[i], stat[j]);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	init();
	int cases, caseNo = 0, val, res, pos, n;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d", &n);
	    vi st;
	    rep(i, 7) {
	        scanf("%d", &val);
	        if (val) st.pb(i);
	    }
	    if (n == 1) res = 1;
	    else {
	        rep(i, stat.size()) if (st == stat[i]) {
	            pos = i;
	            break;
	        }
	        Matrix mat = power(base, n - 1);
	        res = 0;
            rep(j, size) {
                res += mat.a[pos][j];
                res %= mod;
            }
	    }
	    printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}
