//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10706 - Number Sequence
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

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define maxN 40000

int64 sum[maxN];
string digit = "";

string toString(int n) {
	string res = "";
	while (n) {
		res += (n % 10) + 48;
		n /= 10;
	}
	reverse(all(res));
	return res;
}

int countDigit(int n) {
	int res = 0;
	while (n) { res++; n /= 10; }
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int64 tmp = 0LL;
	sum[0] = 0LL;
	for (int i = 1; i < maxN; i++) {
		tmp += countDigit(i);
		sum[i] = sum[i - 1] + tmp;
		digit += toString(i);
	}
	int cases, n;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		int lo = 1, hi = maxN - 1, p = maxN - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (sum[mid] >= n)
				hi = mid - 1, p = min(p, mid);
			else lo = mid + 1;
		}
		cout << digit[n - sum[p - 1] - 1] << endl;
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet