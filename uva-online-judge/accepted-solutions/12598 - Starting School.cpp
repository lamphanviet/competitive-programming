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
#define maxN 50005

int n, k, q, a[maxN], b[maxN], emp[maxN];

int solve(int pos) {
	if (pos < k) return a[pos];
	int lo = 1, hi = k - 1, id = k;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (k - 1 + emp[mid] >= pos) {
			id = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	//printf("%d : %d %d %d\n", pos, id - 1, emp[id - 1], b[id - 1]);
	pos -= k - 1; pos -= emp[id - 1];
	return b[id - 1] + pos;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, pos;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &k, &q);
		fr(i, 1, k) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		b[++k] = 1000000001;
		sort(b + 1, b + k + 1);
		emp[0] = b[0] = 0;
		fr(i, 1, k) emp[i] = emp[i - 1] + (b[i] - b[i - 1] - 1);
		printf("Case %d:\n", ++caseNo);
		while (q--) {
			scanf("%d", &pos);
			printf("%d\n", solve(pos));
		}
	}
	return 0;
}
