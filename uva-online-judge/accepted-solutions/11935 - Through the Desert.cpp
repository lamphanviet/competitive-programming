//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11935 - Through the Desert
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
#define maxN 111


int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int gar1;
	char gar2[maxN], gar3[maxN], cmd[maxN], s[maxN];
	while (gets(s)) {
		if (!strcmp(s, "0 Fuel consumption 0")) break;
		double res = 0.0, cur = 0.0;
		int x = 0, y, n = 0, leak = 0;
		do  {
			sscanf(s, "%d %s", &y, &cmd);
			// go from x to y
			cur += leak * (y - x);
			cur += n * (y - x) / 100.0;
			res = max(res, cur);
			if (cmd[0] == 'G' && cmd[1] == 'o') break; // Goal
			else if (cmd[0] == 'M') leak = 0; // Mechanic
			else if (cmd[0] == 'G' && cmd[1] == 'a') cur = 0.0; // Gas station
			else if (cmd[0] == 'L') leak++; // Leak
			else if (cmd[0] == 'F') {
				sscanf(s, "%d %s %s %d", &gar1, &gar2, &gar3, &n);
			}
			x = y;
		} while (gets(s));
		printf("%.3lf\n", res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet