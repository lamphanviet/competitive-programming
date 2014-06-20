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
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1000111

int n, k, sa[maxN], ra[maxN], tmp[maxN], c[maxN];
char s[maxN], p[505];

void countingSort(int k) {
	int sum = 0, maxi = max(n, 300);
	fill(c, 0);
	rep(i, n) c[i + k < n ? ra[i + k] : 0]++;
	rep(i, maxi) { int t = c[i]; c[i] = sum; sum += t; }
	rep(i, n) tmp[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
	rep(i, n) sa[i] = tmp[i];
}

void constructSA() {
	rep(i, n) sa[i] = i, ra[i] = s[i];
	for (int k = 1, r; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tmp[sa[0]] = r = 0;
		fr(i, 1, n - 1) tmp[sa[i]] = (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k]) ? r : ++r;
		rep(i, n) ra[i] = tmp[i];
	}
}

int cmp(int pos) {
	rep(i, k) {
		if (pos + i >= n - 1) return -1;
		if (s[pos + i] != p[i]) return s[pos + i] < p[i] ? -1 : 1;
	}
	return 0;
}

int getLow(int lo = 1, int hi = n) {
	int pos = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int val = cmp(sa[mid]);
		if (val < 0) lo = mid + 1;
		else if (val >= 0) {
			hi = mid - 1;
			if (val == 0) pos = mid;
		}
	}
	return pos;
}

int getHigh(int lo = 1, int hi = n) {
	int pos = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int val = cmp(sa[mid]);
		if (val <= 0) {
			lo = mid + 1;
			if (val == 0) pos = mid;
		}
		else hi = mid - 1;
	}
	return pos;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, lo, hi;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d %s ", &m, s);
		n = strlen(s); s[n++] = 0;
		constructSA();
		//rep(i, n) printf("%d %d : %s\n", i, sa[i], s + sa[i]);
		printf("Case %d:\n", ++caseNo);
		rep(i, m) {
			scanf(" %s ", p); k = strlen(p);
			//printf("%s: %d %d\n", p, getLow(1, n - 1), getHigh(1, n - 1));
			lo = getLow(1, n - 1);
			if (lo < 0) puts("0");
			else printf("%d\n", getHigh(lo, n - 1) - lo + 1);
		}
	}
	return 0;
}
