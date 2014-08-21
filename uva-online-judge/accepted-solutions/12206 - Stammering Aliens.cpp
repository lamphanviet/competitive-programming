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
#define maxN 40004
#define P 9875321

int n, k, len, pos;
char s[maxN];
uint64 hash[maxN], hashPow[maxN];
vector<pair<uint64, int> > cnt;

int getHash(int lf, int rg) { return (hash[rg + 1] - hash[lf]) * hashPow[n - lf]; }

bool check(int L) {
    cnt.clear();
    for (int i = 0, j = L - 1; j < n; i++, j++) {
        uint64 h = getHash(i, j);
        cnt.pb(mp(h, i));
    }
    sort(all(cnt));
    int counter = 1, tmpPos = -1;
    fr(i, 1, cnt.size() - 1)
        if (cnt[i].ff != cnt[i - 1].ff) {
            if (counter >= k) len = L, tmpPos = max(tmpPos, cnt[i - 1].ss);
            counter = 1;
        }
        else counter++;
    if (counter >= k) len = L, tmpPos = max(tmpPos, cnt.back().ss);
    if (len == L) pos = tmpPos;
    return (len == L);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	hashPow[0] = 1;
	fr(i, 1, maxN - 1) hashPow[i] = hashPow[i - 1] * P;
	while (scanf(" %d ", &k) && k) {
	    scanf(" %s ", s); n = strlen(s);
	    hash[0] = 0;
	    fr(i, 1, n) hash[i] = hash[i - 1] + s[i - 1] * hashPow[i];
	    len = pos = -1;
	    int lo = 1, hi = n;
	    while (lo <= hi) {
	        int mid = (lo + hi) / 2;
	        if (check(mid)) lo = mid + 1;
	        else hi = mid - 1;
	    }
	    if (len < 0) puts("none");
	    else printf("%d %d\n", len, pos);
	}
	return 0;
}
