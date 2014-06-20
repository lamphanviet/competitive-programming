//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10634 - Say NO to Memorization
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
#define maxN 111
#define N 1010
uint64 dp[N][N], sum[N][N];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	uint64 ans, n, k;
	fill(sum, 0);
	fill(dp, 0);
	for (int i=0;i<=1000;i++) sum[0][i] = dp[0][i] = 1;
	for (int i=1;i<=1000;i++)
	   for (int j=0;j<=1000;j++)
	       if (j == 0) {
                dp[i][j] = j;
                sum[i][j]+=sum[i-1][j];
            }
	       else {
                dp[i][j] = sum[i][j-1];
                sum[i][j]=sum[i-1][j] + dp[i][j];
            }
	while ( scanf("%lld %lld",&n, &k) && (k + n)) {
        ans = 0;
        if (n & 1) {
            for (int i=1;i<=n;i+=2)
                ans+=dp[i][k];
        }
        else {
            for (int i=0;i<=n;i+=2)
                ans+=dp[i][k];
        }
        cout << ans << endl;
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
