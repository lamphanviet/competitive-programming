//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10700 - Camel trading
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
#define maxN 10000

char s[maxN];
vector<int> value;

void parse() {
	value.clear();
	int i = 0, len = strlen(s);
	while (i < len) {
		if (isdigit(s[i])) {
			int val = 0;
			while (i < len && isdigit(s[i]))
				val = val * 10 + s[i++] - 48;
			value.pb(val);
		}
		else if (s[i] == '+')
			value.pb(-1), i++;
		else if (s[i] == '*')
			value.pb(-2), i++;
		else i++;
	}
}

int64 findMin(int i) {
	if (i >= value.size()) return 1;
	int64 res = value[i];
	while (i + 1 < value.size())
		if (value[i + 1] == -2) {
			res *= value[i + 2];
			i += 2;
		}
		else break;
	//printf("%d: %d\n", i, res);
	if (i + 1 < value.size()) res += findMin(i + 2);
	return res;
}

int64 findMax(int i) {
	if (i >= value.size()) return 1;
	int64 res = value[i];
	while (i + 1 < value.size())
		if (value[i + 1] == -1) {
			res += value[i + 2];
			i += 2;
		}
		else break;
	//printf("%d: %d\n", i, res);
	if (i + 1 < value.size()) res *= findMax(i + 2);
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf(" %d ", &cases); cases--; ) {
		scanf(" %s ", s);
		parse();
		int64 mx, mn;
		mx = findMax(0);
		//puts("");
		mn = findMin(0);
		printf("The maximum and minimum are %lld and %lld.\n", mx, mn);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
