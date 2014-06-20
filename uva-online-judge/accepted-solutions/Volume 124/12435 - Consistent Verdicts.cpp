//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Online Judge : UVa
// Problem Name : 12435 - Consistent Verdicts
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
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 1000111222
#define eps 1e-7
#define maxN 1010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int ar[5];
char buff[100];
void readLine() {
	gets(buff);
	int len = strlen(buff), i = 0, m = 0;
	while (i < len)
		if (buff[i] != ' ') {
			ar[m] = 0;
			while (i < len && buff[i] != ' ')
				ar[m] = ar[m] * 10 + (buff[i++] - 48);
			m++;
		}
		else i++;
}

int x[maxN], y[maxN], n;
int m, dist[500005];

int getDist(int i, int j) {
	int a = x[i] - x[j];
	int b = y[i] - y[j];
	return (a * a + b * b);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int caseNo, cases = 0;
	readLine();
	caseNo = ar[0];
	while (caseNo--) {
		readLine();
		n = ar[0];
		for (int i = 0; i < n; i++) {
			readLine();
			x[i] = ar[0];
			y[i] = ar[1];
		}
		m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				dist[m++] = getDist(i, j);
		}
		sort(dist, dist + m);
		int res = 0;
		for (int i = 1; i < m; i++)
			if (dist[i] != dist[i - 1]) res++;
		if (m) res++;
		printf("Case %d: %d\n", ++cases, res + 1);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
