//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10755 - Garbage Heap
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
#define INF 9999999999999999LL
#define eps 1e-7
#define maxN 100000

int64 s[25][25][25], a[25][25][25], ans, A, B, C;
int T;

int64 sumAt(int i1, int i2, int j1, int j2, int k){
	return s[i2][j2][k] - s[i1 - 1][j2][k] - s[i2][j1 - 1][k] + s[i1- 1][j1 - 1][k];
}

void readInput(){
	fr(i, 1, A)
		fr(j, 1, B)
			fr(k, 1, C)
				scanf("%lld", &a[i][j][k]);
				
	memset(s, 0, sizeof s);
	fr(i, 1, C) fr(j, 1, A) fr(k, 1, B){
		s[j][k][i] = s[j -1][k][i] + s[j][k-1][i] - s[j-1][k-1][i] + a[j][k][i];
	}
}

void solve(){
	ans = -INF;
	fr(i, 1, A)
		fr(j, i, A)
			fr(k, 1, B)
				fr(l, k, B){
					int y1 = 1;
					while(y1 <= C){
						int64 sum = sumAt(i,j,k,l,y1);
						ans = max(ans, sum);
						if(sum < 0){
							y1++; continue;
						}
						int y2 = y1 + 1;
						bool ok = true;
						while(y2 <= C){
							int64 sum2 = sumAt(i,j,k,l,y2);
							ans = max(ans, sum2);
							if(sum2 < 0 && sum2 + sum < 0){y1 = y2+1;ok = false; break;}
							sum += sum2;
							ans = max(ans, sum);
							y2++;
						}
						if(ok)y1 = y2+1;
					}
				}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	scanf("%d", &T);
	fr(i, 1, T){
		scanf("%lld%lld%lld", &A, &B, &C);
		readInput();
		solve();
		if(i > 1) cout << endl;
		printf("%lld\n", ans);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
