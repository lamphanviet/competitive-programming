//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12501 - Bulky process of bulk reduction
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
#define maxN 100111

int n;
int64 res, inc[maxN * 8], sum[maxN * 8], up[maxN * 8];
char s[110];

void init(int p, int lo, int hi) {
    if (lo == hi) {
        inc[p] = sum[p] = up[p] = 100LL;
        return;
    }
    int c = p * 2, mid = (lo + hi) / 2;
    init(c, lo, mid);
    init(c + 1, mid + 1, hi);
    
    inc[p] = 0;
    sum[p] = sum[c] + sum[c + 1] + inc[p] * (hi - lo + 1);
    up[p] = up[c] + up[c + 1] + (mid + 1 - lo) * sum[c + 1];
    up[p] += inc[p] * (int64)(((hi - lo + 1) * (hi - lo + 2)) / 2);
}

void update(int p, int lo, int hi, int u, int v, int64 val) {
    if (hi < u || v < lo) return;
    int c = p * 2, mid = (lo + hi) / 2;
    if (u <= lo && hi <= v) {
        inc[p] += val;
        if (lo < hi) {
            sum[p] = sum[c] + sum[c + 1] + inc[p] * (int64)(hi - lo + 1);
            up[p] = up[c] + up[c + 1] + (int64)(mid + 1 - lo) * sum[c + 1];
            up[p] += inc[p] * (((hi - lo + 1) * (int64)(hi - lo + 2)) / 2);
        }
        else { // leaf
            sum[p] = up[p] = inc[p];
        }
        return;
    }
    update(c, lo, mid, u, v, val);
    update(c + 1, mid + 1, hi, u, v, val);
    
    sum[p] = sum[c] + sum[c + 1] + inc[p] * (int64)(hi - lo + 1);
    up[p] = up[c] + up[c + 1] + (int64)(mid + 1 - lo) * sum[c + 1];
    up[p] += inc[p] * (int64)(((hi - lo + 1) * (int64)(hi - lo + 2)) / 2);
    
}

void get(int p, int lo, int hi, int u, int v, int64 val) {
    if (hi < u || v < lo) return;
    int c = p * 2, mid = (lo + hi) / 2;
    if (u <= lo && hi <= v) {
        int64 len = lo - u;
        res += up[p];
        res += sum[p] * (int64)len;
        res += val * (int64)(((hi - lo + 1) * (int64)(hi - lo + 2)) / 2);
        res += val * (int64)(hi - lo + 1) * (int64)len;
        return;
    }
    get(c, lo, mid, u, v, val + inc[p]);
    get(c + 1, mid + 1, hi, u, v, val + inc[p]);
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
    int cases, caseNo = 0, m, u, v;
    int64 val;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d %d", &n, &m);
        printf("Case %d:\n", ++caseNo);
        init(1, 1, n);
        while (m--) {
            scanf(" %s %d %d ", s, &u, &v);
            if (s[0] == 'q') {
                res = 0;
                get(1, 1, n, u, v, 0);
                printf("%lld\n", res);
            }
            else { // change
                scanf(" %lld ", &val);
                update(1, 1, n, u, v, val);
            }
        }
    }
}
