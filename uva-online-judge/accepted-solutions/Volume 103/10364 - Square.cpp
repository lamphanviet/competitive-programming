//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10364 - Square
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
#define maxN 21

bool found;
int n, a[maxN], seg;
bool flag[BIT(maxN)];
map<int, int> pos;

void backTrack(int curSum, int counter, int curStt) {
	if (curSum == seg) {
		curSum = 0;
		counter++;
	}
	if (curStt == 0 && counter == 4) found = true;
	if (found) return;
	if (flag[curStt]) return;
	flag[curStt] = true;
	
	int tmpStt = curStt;
	while (tmpStt) {
		int x = AND(tmpStt, -tmpStt);
		int p = pos[x];
		if (curSum + a[p] <= seg) {
			backTrack(curSum + a[p], counter, curStt^x);
		}
		tmpStt ^= x;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	for (int i = 0; i < maxN; i++)
		pos[BIT(i)] = i;
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		seg = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			seg += a[i];
		}
		if (seg % 4) {
			puts("no");
			continue;
		}
		seg /= 4;
		sort(a, a + n);
		found = false;
		for (int i = 0, lm = BIT(n); i < lm; i++)
			flag[i] = false;
		backTrack(0, 0, BIT(n) - 1);
		if (found) puts("yes");
		else puts("no");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet