//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11201 - The problem of the crazy linguist
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
#define maxN 10

const double p[] = { 12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52 };
string na = "aoeui", pa = "bcdfghjklmnpqrstvwxyz";
int n, number[maxN], ok[30], counter;
char word[maxN];
double res;

void init() {
	number[0] = 1;
	for (int i = 1; i < maxN; i++)
		if (i % 2 == 1) number[i] = number[i - 1] * 5;
		else number[i] = number[i - 1] * 21;
	rep(i, na.length()) na[i] -= 'a';
	rep(i, pa.length()) pa[i] -= 'a';
}

double sbc() {
	double res = 0.0;
	rep(i, n) res += (i + 1) * p[word[i]];
	return res;
}

bool aoeui(int ch) {
	ch += 'a';
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
	return false;
}

void solve(int i, double val) {
	if (i == n) {
		counter++;
		res += val;
		return;
	}
	if (i % 2 == 0) {
		rep(j, pa.length())
			if (ok[pa[j]]) {
				ok[pa[j]]--;
				solve(i + 1, val + (i + 1) * p[pa[j]]);
				ok[pa[j]]++;
			}
	}
	else {
		rep(j, na.length())
			if (ok[na[j]]) {
				ok[na[j]]--;
				solve(i + 1, val + (i + 1) * p[na[j]]);
				ok[na[j]]++;
			}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	init();
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s ", word);
		n = strlen(word);
		rep(i, n) word[i] -= 'a';
		counter = 0;
		res = 0.0;
		rep(i, 26) ok[i] = 2;
		solve(1, p[word[0]]);
		//printf("%lf %d %lf\n", res, counter, sbc());
		res /= counter;
		if (sbc() >= res) puts("above or equal");
		else puts("below");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet