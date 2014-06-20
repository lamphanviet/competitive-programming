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
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100111

bool isPrime(int64 n) {
	for (int i = 2, m = sqrt(n); i <= m; i++)
		if (n % i == 0) return false;
	return true;
}

bool check(int64 n) {
	int64 x = 6;
	while (1) {
		if (n <= x) break;
		n -= x;
		x *= 4;
	}
	if (n == 2 || n %2 == 1) return false;
	return true;
}

bool check2(int64 n) {
	int k = 0;
	while (n %2LL==0) { n/=2LL;k++; }
	if(k>0 && n!= 1LL) return true;
	if (k == 0) return false;
	if (k % 2) return false;
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	fr(i, 2, 500000) if (isPrime(i) && check(i)) printf("%d\n", i);
	fr(i, 2, 1000000) if (check(i) != check2(i)) printf("diff %d\n", i);
}

//1000000000000000000
//999999999999999999
//999999999999999989
