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
#define maxN 10111

struct Node {
    int d, f, st, nd;
    Node() {}
} a[maxN];
int n;

string cnt[10];

void init() {
    cnt[0] = "1011111";
    cnt[1] = "0000101";
    cnt[2] = "1110110";
    cnt[3] = "1110101";
    cnt[4] = "0101101";
    cnt[5] = "1111001";
    cnt[6] = "1111011";
    cnt[7] = "1000101";
    cnt[8] = "1111111";
    cnt[9] = "1111101";
}

bool inside(ii p1, ii p2, int x, int y) {
    if (p1.ff == p2.ff) {
        if (p1.ff == x && p1.ss <= y && y <= p2.ss)
            return true;
    }
    if (p1.ss == p2.ss) {
        if (p1.ss == y && p1.ff <= x && x <= p2.ff)
            return true;
    }
    return false;
}

pair<ii, ii> getPoint(int i, int st, int nd, int f) {
    if (i == 0) return mp(mp(st + 1, 2 * f), mp(nd - 1, 2 * f));
    if (i == 1) return mp(mp(st + 1, f), mp(nd - 1, f));
    if (i == 2) return mp(mp(st + 1, 0), mp(nd - 1, 0));
    if (i == 3) return mp(mp(st, f), mp(st, 2 * f - 1));
    if (i == 4) return mp(mp(nd, f), mp(nd, 2 * f - 1));
    if (i == 5) return mp(mp(st, 0), mp(st, f - 1));
    if (i == 6) return mp(mp(nd, 0), mp(nd, f - 1));
}

char solve(int x, int y) {
    int lo = 0, hi = n - 1, pos = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].st <= x && x <= a[mid].nd) {
            pos = mid; break;
        }
        else if (a[mid].nd < x)
            lo = mid + 1;
        else hi = mid - 1;
    }
    if (pos < 0) return '.';
    rep(i, 7) {
        if (cnt[a[pos].d][i] == '1') {
            pair<ii, ii> point = getPoint(i, a[pos].st, a[pos].nd, a[pos].f);
            if (inside(point.ff, point.ss, x, y)) {
                if (i < 3) return '_';
                return '|';
            }
        }
    }
    return '.';
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	init();
	int m, x, y;
	while (scanf("%d", &n) && n) {
	    int next = 0;
	    rep(i, n) {
	        scanf("%d %d", &a[i].d, &a[i].f);
	        a[i].st = next;
	        a[i].nd = next + a[i].f + 1;
	        next = a[i].nd + 2;
	    }
	    scanf("%d", &m);
	    while (m--) {
	        scanf("%d %d ", &x, &y);
	        putchar(solve(x, y));
	        puts("");
	    }
	}
	return 0;
}
