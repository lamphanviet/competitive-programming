//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11082 - Matrix Decompressing
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
#define maxN 50

int n, m, c[maxN][maxN], f, st, nd, p[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		int u = p[v];
		augment(u, min(minEdge, c[u][v]));
		c[u][v] -= f; c[v][u] += f;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		fill(c, 0);
		scanf("%d %d", &n, &m);
		st = n + m + 1; nd = st + 1;
		int prev = 0, cur;
		fr(i, 1, n) {
			scanf("%d", &cur);
			c[st][i] = cur - prev - m;
			prev = cur;
		}
		prev = 0;
		fr(j, 1, m) {
			scanf("%d", &cur);
			c[j + n][nd] = cur - prev - n;
			prev = cur;
		}
		fr(i, 1, n) fr(j, 1, m)
			c[i][j + n] = 19;
			
		do {
			f = 0;
			queue<int> q; q.push(st);
			fr(i, 1, nd) p[i] = -1; p[st] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == nd) break;
				fr(v, 1, nd)
					if (c[u][v] > 0 && p[v] == -1)
						p[v] = u, q.push(v);
			}
			augment(nd, 20);
		} while (f);
		
		printf("Matrix %d\n", ++caseNo);
		fr(i, 1, n) {
			fr(j, 1, m - 1) printf("%d ", 20 - c[i][j + n]);
			printf("%d\n", 20 - c[i][n + m]);
		}
		puts("");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */