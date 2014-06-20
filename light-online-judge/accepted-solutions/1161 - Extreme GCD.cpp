//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1161 - Extreme GCD 
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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10011

int n, a[maxN];
int64 c[maxN], maxVal, cnt[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, 4) c[i] = 0; c[4] = 1;
	fr(i, 5, maxN - 1) c[i] = (c[i - 1] * i) / (i - 4);
	int cases, caseNo = 0;
    for (scanf("%d ", &cases); cases--; ) {
        scanf("%d", &n);
        rep(i, maxN) cnt[i] = 0;
        maxVal = 0;
        rep(i, n) {
            scanf("%d", &a[i]);
            for (int j = 1; j * j <= a[i]; j++)
                if (a[i] % j == 0) {
                    cnt[j]++;
                    if (j != a[i] / j) cnt[a[i] / j]++;
                }
            maxVal = max(maxVal, (int64)a[i]);
        }
        
        frr(i, maxVal, 1) {
            cnt[i] = c[cnt[i]];
            for (int j = i + i; j <= maxVal; j += i)
                cnt[i] -= cnt[j];
        }
        
        printf("Case %d: %lld\n", ++caseNo, cnt[1]);
    }
	return 0;
}
