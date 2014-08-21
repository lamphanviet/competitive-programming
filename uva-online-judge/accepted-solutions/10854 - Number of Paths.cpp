//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10854 - Number of Paths 
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
#define maxN 100

char s[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf(" %d ", &cases); cases--; ) {
		stack<int64> st;
		st.push(1);
		while (scanf(" %s ", s)) {
			if (s[0] == 'E' && s[3] == 'P') break; // end program
			if (s[0] == 'S') continue; // s - do nothing
			if (s[0] == 'I') { // if
				st.push(-1);
				st.push(1);
			}
			else if (s[1] == 'L') { // else
				st.push(-2);
				st.push(1);
			}
			else { // end if
				int64 a = 1, b = 1;
				while (st.top() != -2) {
					a *= st.top();
					st.pop();
				}
				st.pop();
				while (st.top() != -1) {
					b *= st.top();
					st.pop();
				}
				st.pop();
				st.push(a + b);
			}
		}
		int64 res = 1;
		while (!st.empty()) {
			res *= st.top();
			st.pop();
		}
		printf("%lld\n", res);
	}
	return 0;
}
