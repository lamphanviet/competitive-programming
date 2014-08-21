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
#define maxN 111

char s[maxN];
int64 len[30][10];

string text[10];
map<string, int> val;
int value[300];

int getValue(char ch) {
	foreach(it, val) {
		rep(i, it->ff.length())
			if (ch == it->ff[i]) return it->ss;
	}
}

void init() {
	text[2] = "TWO";
	text[3] = "THREE"; text[4] = "FOUR";
	text[5] = "FIVE"; text[6] = "SIX";
	text[7] = "SEVEN"; text[8] = "EIGHT";
	text[9] = "NINE";
	val["ABC"] = 2;
	val["DEF"] = 3;
	val["GHI"] = 4;
	val["JKL"] = 5;
	val["MNO"] = 6;
	val["PQRS"] = 7;
	val["TUV"] = 8;
	val["WXYZ"] = 9;
	fr(i, 'A', 'Z') value[i] = getValue(i);
	
	fr(j, 2, 9) len[1][j] = text[j].length();
	fr(i, 2, 22) fr(j, 2, 9) {
		len[i][j] = 0;
		rep(u, text[j].length())
			len[i][j] += len[i - 1][value[text[j][u]]];
	}
}

char solve(int i, int j, int k) {
	if (i == 0) return text[j][k - 1];
	rep(u, text[j].length()) {
		if (k > len[i][value[text[j][u]]]) k -= len[i][value[text[j][u]]];
		else return solve(i - 1, value[text[j][u]], k);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	init();
	char res;
	int cases, caseNo = 0, n, k;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s %d %d ", s, &n, &k);
		int slen = strlen(s);
		rep(i, slen) {
			if (k > len[n][value[s[i]]]) k -= len[n][value[s[i]]];
			else {
				res = solve(n - 1, value[s[i]], k);
				break;
			}
		}
		printf("Case %d: %c\n", ++caseNo, res);
	}
	//rep(i, 3) printf("%c", solve(0, value['A'], i + 1));
	return 0;
}
