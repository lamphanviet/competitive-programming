//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12532 - Interval Product
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

int n, zero[maxN], neg[maxN], a[maxN];

void update(int i, int val, int *tree) {
    while (i <= n) {
        tree[i] += val;
        i += (-i & i);
    }
}

int get(int i, int *tree) {
    int res = 0;
    while (i > 0) {
        res += tree[i];
        i -= (-i & i);
    }
    return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	char ch;
	int m, u, v;
	while (scanf("%d %d", &n, &m) != EOF) {
	    fr(i, 1, n) zero[i] = neg[i] = 0;
	    fr(i, 1, n) {
	        scanf("%d", &a[i]);
	        if (a[i] == 0) update(i, 1, zero);
	        if (a[i] < 0) update(i, 1, neg);
	    }
	    while (m--) {
	        scanf(" %c %d %d ", &ch, &u, &v);
	        if (ch == 'C') {
	        	if (a[u] == 0 && v == 0) continue;
	        	if (a[u] > 0 && v > 0) continue;
	            if (a[u] == 0) update(u, -1, zero);
	            if (a[u] < 0) update(u, -1, neg);
	            a[u] = v;
                if (a[u] == 0) update(u, 1, zero);
	            if (a[u] < 0) update(u, 1, neg);
	        }
	        else {
	            int z = get(v, zero) - get(u - 1, zero);
	            if (z > 0) {
	                putchar('0'); continue;
	            }
	            int g = get(v, neg) - get(u - 1, neg);
	            if (g % 2 == 0) putchar('+');
	            else putchar('-');
	        }
	    }
	    puts("");
	}
	return 0;
}
