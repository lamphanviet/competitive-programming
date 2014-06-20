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
#define maxN 1000011

bool isPrime[maxN];
vi prime;
void sieve() {
    fill(isPrime, true);
    for (int i = 3; i * i < maxN; i += 2)
        if (isPrime[i])
            for (int j = i + i; j < maxN; j += i + i)
                isPrime[j] = false;
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isPrime[i]) prime.pb(i);
}

int64 phi(int64 val) {
    int64 res = val;
    for (int i = 0; i < prime.size() && prime[i] * (int64)prime[i] <= val; i++)
        if (val % prime[i] == 0) {
            res /= prime[i];
            res *= prime[i] - 1;
            while (val % prime[i] == 0) val /= prime[i];
        }
    if (val > 1) {
        res /= val;
        res *= val - 1;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    sieve();
    int64 n, k;
    int cases, caseNo = 0, m;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%lld %d", &n, &m);
        printf("Case %d\n", ++caseNo);
        vector< pair<int64, int64> > v;
        for (int64 i = 1; i * i <= n; i++)
            if (n % i == 0) {
                v.pb(mp(i, phi(n / i)));
                v.pb(mp(n / i, phi(i)));
            }
        sort(all(v));
        for (int i = 1; i < v.size(); i++)
            v[i].ss += v[i - 1].ss;
        while (m--) {
            scanf("%lld", &k);
            int lo = 0, hi = v.size() - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (v[mid].ff <= k) {
                    lo = mid + 1;
                    pos = mid;
                }
                else hi = mid - 1;
            }
            if (pos == -1) puts("0");
            else printf("%lld\n", v[pos].ss);
        }
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
