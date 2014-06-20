//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1241 - Jollybee Tournament - UVa
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
#define maxN 1050

int n, m, k, res;
bool mark[maxN];

bool go(int x, int y) {
    //printf("%d %d\n", x, y);
    bool a, b;
    if (x + 1 == y) {
        a = mark[x];
        b = mark[y];
    }
    else {
        int mid = (x + y) / 2;
        a = go(x, mid);
        b = go(mid + 1, y);
    }
    if ((!a || !b) && (a || b)) res++;
    //printf("%d %d: %d\n", x, y, !a || !b);
    return a || b;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d", &n, &m);
	    fill(mark, true);
	    while (m--) {
	        scanf("%d", &k);
	        mark[k] = false;
	    }
	    res = 0;
	    go(1, BIT(n));
	    printf("%d\n", res);
	}
	return 0;
}
