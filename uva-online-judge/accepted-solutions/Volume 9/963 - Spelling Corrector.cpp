//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 963 - Spelling Corrector
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
#define maxN 100000

int n, m, f[10][10];
string s;
vector<string> word;

int getMin(const string &a, const string &b) {
	int p = a.length(), q = b.length();
	fill(f, 0);
	fr(j, 0, q) f[0][j] = j;
	fr(i, 1, p) {
		f[i][0] = i;
		fr(j, 1, q) {
			f[i][j] = min(f[i - 1][j] + 3, f[i][j - 1] + 3);
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + 5);
			if (a[i - 1] == b[j - 1]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
		}
	}
	return f[p][q];
}

int find() {
	int pos = 0, minCost = INF, cost;
	rep(i, n) {
		cost = getMin(s, word[i]);
		if (cost < minCost) pos = i, minCost = cost;
	}
	return pos;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	scanf(" %d ", &n); word.resize(n);
	rep(i, n) cin >> word[i];
	scanf(" %d ", &m);
	rep(i, m) {
		cin >> s;
		cout << word[find()];
		if ((i + 1) % 10 == 0) puts("");
		else putchar(' ');
	}
	if (m % 10) puts("");
	return 0;
}