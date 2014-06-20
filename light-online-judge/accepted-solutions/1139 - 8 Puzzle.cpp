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
#define maxN 5

const int n = 3;
const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };
struct Puzzle {
	int x, y;
	char a[n][n];
	Puzzle() {}
	string toString() {
		string res = "";
		rep(i, n) rep(j, n)
			res += a[i][j];
		return res;
	}
};

map<string, int> idx;
int res[181440], cnt;
Puzzle puz[181440];

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < n); }

int getIndex(Puzzle p) {
	string s = p.toString();
	if (idx.count(s)) return idx[s];
	puz[cnt] = p;
	return idx[s] = cnt++;
}

void preCompute() {
	Puzzle p;
	rep(i, n) rep(j, n)
		p.a[i][j] = i * n + j + 1;
	p.a[n - 1][n - 1] = 0;
	p.x = p.y = n - 1;
	cnt = 0;
	queue<int> q;
	int startId = getIndex(p);
	q.push(startId);
	res[startId] = 0;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		p = puz[id];
		int x = p.x, y = p.y;
		rep(i, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!inside(xx, yy)) continue;
			swap(p.a[x][y], p.a[xx][yy]);
			
			p.x = xx; p.y = yy;
			int nextId = getIndex(p);
			if (nextId == cnt - 1) {
				q.push(nextId);
				res[nextId] = res[id] + 1;
			}
			
			swap(p.a[x][y], p.a[xx][yy]);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	preCompute();
	int cases, caseNo = 0, val;
	for (scanf("%d", &cases); cases--; ) {
		string s = "";
		rep(i, n) rep(j, n) {
			scanf("%d", &val);
			s += val;
		}
		printf("Case %d: ", ++caseNo);
		if (idx.count(s)) printf("%d\n", res[idx[s]]);
		else puts("impossible");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */