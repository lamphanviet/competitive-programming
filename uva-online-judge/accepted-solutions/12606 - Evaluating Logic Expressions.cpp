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
#define maxN 100111

int n, m, len;
bool op1[maxN][2], op2[maxN][2][2], kind[maxN];
map<string, int> opIdx;
map<string, bool> value;
char s[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int caseNo = 0;
	string tmp, ope, var;
	while (scanf("%d %d", &n, &m) && (n >= 0 && m >= 0)) {
		opIdx.clear();
		rep(i, n) {
			cin >> ope;
			opIdx[ope] = i;
			kind[i] = 0;
			rep(j, 2) {
				cin >> tmp;
				op1[i][j] = (tmp[0] == 't');
			}
		}
		rep(i, m) {
			cin >> ope;
			opIdx[ope] = i + n;
			kind[i + n] = 1;
			rep(j, 2) rep(k, 2) {
				cin >> tmp;
				op2[i + n][j][k] = (tmp[0] == 't');
			}
		}
		scanf(" ");
		gets(s); len = strlen(s);
		value.clear();
		while (cin >> var && var != "*") {
			cin >> tmp;
			value[var] = (tmp[0] == 't');
		}
		vector<int> ex;
		stack<int> st;
		for (int i = 0; i < len; ) {
			if (s[i] != ' ') {
				if (s[i] == '(') {
					st.push(-1);
					i++;
				}
				else if (s[i] == ')') {
					i++;
					while (!st.empty() && st.top() != -1) {
						ex.pb(st.top());
						st.pop();
					}
					st.pop();
				}
				else if (s[i] == toupper(s[i])) { // operator
					tmp = "";
					while (i < len && isalpha(s[i]))
						tmp += s[i++];
					st.push(opIdx[tmp]);
				}
				else { // variable
					tmp = "";
					while (i < len && isalpha(s[i])) 
						tmp += s[i++];
					if (value.count(tmp)) {
						ex.pb(value[tmp] ? -1 : -2);
					}
					else ex.pb(-3);
				}
			}
			else i++;
		}
		while (!st.empty()) {
			ex.pb(st.top());
			st.pop();
		}
		// -1: true, -2: false, -3: both, >= 0: operator
		stack<int> v;
		//rep(i, ex.size()) printf("%d ", ex[i]); puts("");
		rep(i, ex.size()) {
			if (ex[i] == -1) v.push(2);
			else if (ex[i] == -2) v.push(1);
			else if (ex[i] == -3) v.push(3);
			else {
				int id = ex[i];
				if (kind[id] == 0) {
					int top = v.top(), res = 0; v.pop();
					rep(k, 2) if (top & BIT(k))
						res |= BIT(op1[id][k]);
					v.push(res);
					//printf("res1 %d\n", res);
				}
				else {
					int b = v.top(); v.pop();
					int a = v.top(); v.pop();
					int res = 0;
					rep(u, 2) if (a & BIT(u)) rep(v, 2) if (b & BIT(v))
						res |= BIT(op2[id][u][v]);
					v.push(res);
					//printf("res2 %d\n", res);
				}
			}
		}
		int res = v.top(); v.pop();
		printf("Case %d: ", ++caseNo);
		if (res == 3) puts("unknown");
		else if (res == 2) puts("true");
		else puts("false");
	}
	return 0;
}
