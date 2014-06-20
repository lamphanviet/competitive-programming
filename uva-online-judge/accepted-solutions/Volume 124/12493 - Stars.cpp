//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12493 - Stars - UVa
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
#define maxN 46341

bool isPrime[maxN];
vi prime;

void sieve() {
    fill(isPrime, true);
    for (int i = 3; i * i < maxN; i += 2)
        if (isPrime[i])
            for (int j = i * i; j < maxN; j += i + i)
                isPrime[j] = false;
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isPrime[i]) prime.pb(i);
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int n;
	sieve();
	while (scanf("%d", &n) != EOF) {
	    int m = n, nn = n;
	    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= nn; i++)
            if (n % prime[i] == 0) {
                while (nn % prime[i] == 0) nn /= prime[i];
                m /= prime[i];
                m *= prime[i] - 1;
            }
        if (nn != 1) {
            m /= nn;
            m *= nn - 1;
        }
	    printf("%d\n", m / 2);
	}
	return 0;
}
