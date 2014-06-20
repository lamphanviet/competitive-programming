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
#define maxN 15
#define N 13

int A, B, C, D;
double p[maxN][maxN][maxN][maxN][5][5];

double solve() {
	int sum = A + B + C + D;
	if (sum == 54) return 54.0;
	if (sum == 0) return 0.0;
	if (sum > 54) return -1.0;
	double res = 54.0;
	fr(a, 0, N) fr(b, 0, N) fr(c, 0, N) fr(d, 0, N) fr(x, 0, 4) fr(y, 0, 4) p[a][b][c][d][x][y] = 0.0;
	p[0][0][0][0][0][0] = 1.0;
	fr(a, 0, N) fr(b, 0, N) fr(c, 0, N) fr(d, 0, N) fr(x, 0, 4) fr(y, 0, 4) {
		double rest = 54 - (a + b + c + d + (x > 0) + (y > 0));
		if (rest == 0) continue;
		double pa, pb, pc, pd;
		pa = (13.0 - a) / rest;
		pb = (13.0 - b) / rest;
		pc = (13.0 - c) / rest;
		pd = (13.0 - d) / rest;
		p[a + 1][b][c][d][x][y] += p[a][b][c][d][x][y] * pa;
		p[a][b + 1][c][d][x][y] += p[a][b][c][d][x][y] * pb;
		p[a][b][c + 1][d][x][y] += p[a][b][c][d][x][y] * pc;
		p[a][b][c][d + 1][x][y] += p[a][b][c][d][x][y] * pd;
		if (x == 0) {
			fr(xx, 1, 4) p[a][b][c][d][xx][y] += p[a][b][c][d][x][y] * (1.0 / rest);
		}
		if (y == 0) {
			fr(yy, 1, 4) p[a][b][c][d][x][yy] += p[a][b][c][d][x][y] * (1.0 / rest);
		}
		int aa = a, bb = b, cc = c, dd = d;
		if (x == 1) aa++;
		else if (x == 2) bb++;
		else if (x == 3) cc++;
		else if (x == 4) dd++;
		if (y == 1) aa++;
		else if (y == 2) bb++;
		else if (y == 3) cc++;
		else if (y == 4) dd++;
		if (aa == A || bb == B || cc == C || dd == D) res = min(res, p[a][b][c][d][x][y] * (54 - rest));
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d %d %d %d ", &A, &B, &C, &D);
		printf("Case %d: %.10lf\n", ++caseNo, solve());
	}
	double val = 1.0 / 4.0;
	double res = 0.5;
	fr(i, 3, 10000) {
		val /= 2.0;
		res += val * (i - 2) * i;
	}
	printf("%lf\n", res);
	return 0;
}
