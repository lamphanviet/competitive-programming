//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10126 - Zipf's Law
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
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define OR(a,b) ((a) | (b))
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

int n;
char s[10111];
map<string, int> counter;

bool alpha(char ch) {
    return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	bool line = false;
	while (scanf("%d ", &n) != EOF) {
        counter.clear();
        while (gets(s)) {
            if (strcmp(s, "EndOfText") == 0) break;
            int len = strlen(s), i = 0;
            string word = "";
            while (i < len)
                if (alpha(s[i])) {
                    word = "";
                    while (i < len &&  alpha(s[i]))
                        word += tolower(s[i++]);
                    counter[word]++;
                }
                else i++;
        }
        vector<string> res;
        foreach(it, counter)
            if (it->ss == n)
                res.pb(it->ff);
        if (line) puts(""); line = true;
        if (res.size() == 0) puts("There is no such word.");
        else rep(i, res.size())
            cout << res[i] << endl;
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
