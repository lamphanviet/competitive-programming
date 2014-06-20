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
#include <deque>

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
#define maxN 15005

int n, len[3], id[maxN], cnt[3];
int sa[maxN], lcp[maxN], tmp1[maxN], tmp2[maxN];
string s;

void countingSort(int k, int *c, int *ra, int *tmp) {
	int sum = 0, m = max(n, 300);
	rep(i, m) c[i] = 0;
	rep(i, n) c[i + k < n ? ra[i + k] : 0]++;
	rep(i, m) { int t = c[i]; c[i] = sum; sum += t; }
	rep(i, n) tmp[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
	rep(i, n) sa[i] = tmp[i];
}

void constructSA(int *c, int *ra, int *tmp) {
	rep(i, n) sa[i] = i, ra[i] = s[i];
	for (int k = 1; k < n; k <<= 1) {
		countingSort(k, c, ra, tmp);
		countingSort(0, c, ra, tmp);
		int r = tmp[sa[0]] = 0;
		fr(i, 1, n - 1) tmp[sa[i]] = (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k]) ? r : ++r;
		rep(i, n) ra[i] = tmp[i];
	}
}

void computeLCP(int *phi, int *plcp) {
	phi[sa[0]] = -1;
	fr(i, 1, n - 1) phi[sa[i]] = sa[i - 1];
	for (int i = 0, L = 0; i < n; i++) {
		if (phi[i] == -1) { plcp[i] = 0; continue; }
		while (i + L < n && phi[i] + L < n && s[i + L] == s[phi[i] + L]) L++;
		plcp[i] = L;
		L = max(L - 1, 0);
	}
	rep(i, n) lcp[i] = plcp[sa[i]];
}

int getType(int pos) {
	if (pos < len[0]) return 0;
	if (pos < len[1]) return 1;
	return 2;
}

int getResult() {
	map<int, int> value;
	int cnt[] = { 0, 0, 0 }, diffType = 0, res = 0, prev = 4;
	fr(i, 4, n - 1) {
		if (++cnt[id[i - 1]] == 1) diffType++;
		if (++cnt[id[i]] == 1) diffType++;
		value[lcp[i]]++;
		while (prev <= i && diffType == 3) {
			res = max(res, value.begin()->ff);
			if (--value[lcp[prev]] == 0) value.erase(lcp[prev]);
			if (--cnt[id[prev - 1]] == 0) diffType--;
			if (--cnt[id[prev]] == 0) diffType--;
			prev++;
		}
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	string s1, s2;
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		cin >> s >> s1 >> s2;
		len[0] = s.length();
		len[1] = len[0] + 1 + s1.length();
		len[2] = len[1] + 1 + s2.length();
		s += "." + s1 + "." + s2 + char(0);
		n = s.length();
		constructSA(lcp, tmp1, tmp2);
		computeLCP(tmp1, tmp2);
		id[3] = getType(sa[3]);
		fr(i, 4, n - 1) {
			id[i] = getType(sa[i]);
			lcp[i] = min(lcp[i], min(len[id[i]] - sa[i], len[id[i - 1]] - sa[i - 1]));
		}
		printf("Case %d: %d\n", ++caseNo, getResult());
	}
	return 0;
}
