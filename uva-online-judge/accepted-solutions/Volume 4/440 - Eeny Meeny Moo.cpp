//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 440 - Eeny Meeny Moo
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

const int a[] = { 0, 1, 2, 2, 5, 2, 4, 3, 11, 2, 3, 8, 16, 4, 21, 6, 5, 2, 11, 20, 34, 8, 15, 10, 7, 13, 11, 13, 45, 18, 23, 8, 3, 2, 25, 75, 42, 13, 5, 23, 13, 50, 16, 18, 89, 38, 8, 39, 30, 29, 38, 7, 45, 23, 137, 46, 63, 17, 48, 5, 46, 34, 140, 33, 39, 2, 28, 29, 79, 33, 48, 3, 10, 46, 120, 6, 37, 17, 8, 44, 15, 160, 20, 35, 144, 104, 179, 153, 24, 8, 265, 19, 9, 62, 7, 139, 19, 44, 93, 182, 27, 158, 185, 193, 17, 82, 3, 11, 43, 55, 21, 41, 146, 29, 80, 59, 8, 29, 66, 19, 160, 59, 28, 129, 127, 120, 72, 45, 157, 2, 63, 127, 81, 318, 513, 98, 28, 32, 231, 236, 411, 26, 45, 5, 303, 228, 66, 9, 205, 65, 39 };
/*
bool f[155];
int last(int n, int k) {
	fr(i, 1, n) f[i] = true;
	f[1] = false;
	int x = 1, m = 1;
	while (1) {
		int counter = 0;
		while (counter < k) {
			x = x % n + 1;
			if (f[x]) counter++;
		}
		f[x] = false;
		m++;
		if (m == n) return x;
	}
}
*/

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	/*printf("const int a[] = { 0, 1, 2, ");
	for (int i = 3; i<= 150; i++) {
		int j = 1;
		while (true) {
			if (last(i, j) == 2) {
				printf("%d, ", j);
				break;
			}
			j++;
		}
	}*/
	int n;
	while (scanf("%d", &n) && n) {
		printf("%d\n", a[n]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet