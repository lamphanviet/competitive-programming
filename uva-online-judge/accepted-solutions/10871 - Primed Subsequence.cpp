//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10871 - Primed Subsequence
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
#define maxN 1000001

bool isP[maxN];
vi prime;

void sieve() {
	fill(isP, true);
	isP[0] = isP[1] = false;
	for (int i = 4; i < maxN; i += 2) isP[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isP[i])
			for (int j = i * i; j < maxN; j += i + i)
				isP[j] = false;
	prime.pb(2);
	for (int i = 3; i < maxN; i += 2)
		if (isP[i]) prime.pb(i);
}

bool isPrime(int n) {
	if (n < maxN) return isP[n];
	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++)
		if (n % prime[i] == 0) return false;
	return true;
}

int n, a[10111], sum[10111];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	sieve();
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		sum[0] = 0;
		fr(i, 1, n) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		bool found = false;
		fr(len, 2, n) {
			for (int i = 1, j = len; j <= n; i++, j++)
				if (isPrime(sum[j] - sum[i - 1])) {
					printf("Shortest primed subsequence is length %d:", len);
					fr(k, i, j) printf(" %d", a[k]); puts("");
					found = true;
					break;
				}
			if (found) break;
		}
		if (!found) puts("This sequence is anti-primed.");
	}
	return 0;
}