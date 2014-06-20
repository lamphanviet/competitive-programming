//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 202 - Repeating Decimals
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

int n, m, xx;
string s;
map<int, int> idx;

string toString(int k) {
    string res = "";
    do {
        res += k % 10 + 48;
        k /= 10;
    } while (k);
    return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d/%d = ", n, m);
        string st = toString(n / m);
        n = (n -  m * (int)(n / m)) * 10;
        s = "";
        idx.clear();
        int len = 0, x = -1, y = -1;
        rep(_, 10000) {
            if (idx.count(n)) {
                x = idx[n];
                y = s.length() - 1;
                break;
            }
            else idx[n] = s.length();
            int k = n / m;
            string add = toString(k);
            s += add;
            len += add.length();
            n -= k * m;
            n *= 10;
        }
        cout << st << ".";
        
        string res = "";
        rep(i, x) res += s[i];
        res += '(';
        fr (i, x, y) res += s[i];
        xx = y - x + 1;
        if (res.length() - 1 <= 50) cout << res << ")" << endl;
        else {
            if (x > 50) {
                rep(i, 50) putchar(res[i]);
                puts("");
            }
            else {
                rep(i, 51) putchar(res[i]);
                puts("...)");
            }
        }
        printf("   %d = number of digits in repeating cycle\n", xx);
        puts("");
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
