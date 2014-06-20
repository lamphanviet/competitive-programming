//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1263 - Mines - UVa
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
#define maxN 2002

int n, x[maxN], y[maxN], d[maxN];
bool c[maxN][maxN], act[maxN];
int num[maxN], low[maxN], number, reg[maxN], nreg;
stack<int> st;

bool cal(int x1, int x2, int y1, int y2, int x0, int y0) {
    return (x1 <= x0 && x0 <= x2 && y1 <= y0 && y0 <= y2);
}

void visit(int u) {
    st.push(u);
    low[u] = num[u] = ++number;
    rep(v, n) {
        if (!c[u][v] || reg[v]) continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            visit(v);
            low[u] = min(low[v], low[u]);
        }
    }
    if (low[u] == num[u]) {
        ++nreg;
        int v;
        do {
            v = st.top(); st.pop();
            reg[v] = nreg;
        } while (v != u);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
	    fill(c, false);
	    scanf("%d", &n);
	    rep(i, n) {
	        scanf("%d %d %d", &x[i], &y[i], &d[i]);
	        d[i] /= 2;
	    }
	    rep(i, n) rep(j, n)
            if (i == j) c[i][j] = true;
            else c[i][j] = cal(x[i] - d[i], x[i] + d[i], y[i] - d[i], y[i] + d[i], x[j], y[j]);
            
        nreg = number = 0;
        st = stack<int>();
        fill(num, 0); fill(reg, 0);
        rep(i, n) if (num[i] == 0)
            visit(i);
            
        fill(act, true);
        rep(i, n) rep(j, n)
            if (reg[i] != reg[j] && c[i][j])
                act[reg[j]] = false;
                
        //rep(i, n) printf(" %d", reg[i]); puts("");
        int res = 0;
        fr(i, 1, nreg) if (act[i]) res++;
        printf("%d\n", res);
	}
	return 0;
}
