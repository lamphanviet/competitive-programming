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
#define maxN 26

int n, k, cnt[maxN];
char s[maxN];
int64 c[maxN][maxN];

int64 getNumber(int all) {
	int64 res = 1;
	rep(i, maxN) {
		res *= c[all][cnt[i]];
		all -= cnt[i];
	}
	return res;
}

void solve() {
	fill(cnt, 0);
	rep(i, n) cnt[s[i] - 'a']++;
	if (k > getNumber(n)) {
		puts("Impossible");
		return;
	}
	rep(i, n) {
		int64 cur = 0;
		rep(j, maxN) if (cnt[j]) {
			cnt[j]--;
			int64 next = cur + getNumber(n - i - 1);
			if (next >= k) {
				s[i] = j + 'a';
				k -= cur;
				break;
			}
			cnt[j]++;
			cur = next;
		}
	}
	puts(s);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, maxN) {
		c[i][0] = c[i][i] = 1;
		fr(j, 1, i - 1) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s %d ", s, &k); n = strlen(s);
		printf("Case %d: ", ++caseNo); solve();
	}
	return 0;
}
