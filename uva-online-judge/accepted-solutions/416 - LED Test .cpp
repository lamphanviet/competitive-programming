//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 416 - LED Test 
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
#define maxN 11

int n, light[maxN], activeLED;
const int num[] = { 126, 48, 109, 121, 51, 91, 95, 112, 127, 123 };

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char s[maxN];
	while (scanf(" %d ", &n) && n) {
		for (int i = 0; i < n; i++) {
			gets(s);
			light[i] = 0;
			for (int j = 0; j < 7; j++) {
				light[i] <<= 1;
				if (s[j] == 'Y') light[i] |= 1;
			}
		}
		bool ok = false;
		for (int start = 9; start >= n - 1 && !ok; start--) {
			bool check = true;
			int activeLED = BIT(7) - 1;
			for (int i = start, j = 0; j < n && check; i--, j++) {
				if (AND(activeLED, light[j]) != light[j]) check = false;
				if (AND(num[i], light[j]) != light[j]) check = false;
				int dieLED = AND(num[i], ~light[j]);
				activeLED &= ~dieLED;
			}
			ok = check;
		}
		if (!ok) printf("MIS");
		puts("MATCH");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet