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
#define maxN 16

int n, f[BIT(maxN)][maxN], cnt[maxN][maxN];
string s[maxN];

int step(int state, int id) {
	if (f[state][id] != -1) return f[state][id];
	int next = state ^ BIT(id);
	if (next == 0) return f[state][id] = s[id].length();
	f[state][id] = INF;
	rep(i, n) if (next & BIT(i)) {
		step(next, i);
		f[state][id] = min(f[state][id], f[next][i] + cnt[id][i]);
	}
}

int getCnt(const string &a, const string &b) {
	int alen = a.length();
	rep(i, alen)
		if (a.substr(i, alen - i) == b.substr(0, alen - i)) return i;
	return alen;
}

string res;

void findResult(int state, int id, string cur) {
	if (cur > res) return;
	int next = state ^ BIT(id);
	if (next == 0) {
		cur += s[id];
		if (cur < res) res = cur;
		return;
	}
	rep(i, n) if (next & BIT(i) && f[state][id] == f[next][i] + cnt[id][i]) {
		findResult(next, i, cur + s[id].substr(0, cnt[id][i]));
	}
}

string solve() {
	rep(i, n) rep(j, n) if (i != j && s[i].find(s[j]) != string::npos)
		s[j] = "";
	int m = 0;
	rep(i, n) if (s[i] != "") s[m++] = s[i];
	n = m;
	sort(s, s + n);
	rep(i, n) rep(j, n) if (i != j)
		cnt[i][j] = getCnt(s[i], s[j]);
	fill(f, -1);
	int len = INF, state = BIT(n) - 1;
	rep(i, n) {
		step(state, i);
		len = min(len, f[state][i]);
	}
	res = "z";
	rep(i, n) if (f[state][i] == len)
		findResult(state, i, "");
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d ", &n);
		rep(i, n) cin >> s[i];
		printf("Case %d: ", ++caseNo); cout << solve() << endl;
	}
	return 0;
}
