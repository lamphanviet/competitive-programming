//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 533 - Equation Solver
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

struct Number {
    int a, b, op;
    char ch;
    Number() {
        a = b = 0;
        op = -1;
    }
    Number(int o, char c) {
		op = o; ch = c;
	}
    Number(int aa, int bb = 0) {
        a = aa; b = bb;
        op = -1;
    }
    
    Number compute(Number num, Number opr) {
        if (opr.ch == '-') {
            num.a = a - num.a;
            num.b = b - num.b;
        }
        else if (opr.ch == '+') {
            num.a = a + num.a;
            num.b = b + num.b;
        }
        else if (opr.ch == '*') {
            num.a = a * num.b + b * num.a;
            num.b = b * num.b;
        }
        return num;
    }
};

int n;
string s;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int caseno = 0;
	char str[1000];
	while (gets(str)) {
        n = strlen(str);
        s = "";
        rep(i, n) if (str[i] == '=') {
            rep(j, i) s += str[j];
            s += "-(";
            fr(j, i + 1, n - 1) s += str[j];
            s += ")";
            break;
        }

        vector<Number> a;
        int i = 0; n = s.length();
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            if (s[i] == 'x') {
                a.pb(Number(1, 0));
                i++;
            }
            else if (s[i] == '(' || s[i] == ')') {
                a.pb(Number(0, s[i]));
                i++;
            }
            else if (s[i] == '+' || s[i] == '-') {
                a.pb(Number(1, s[i]));
                i++;
            }
            else if (s[i] == '*') {
                a.pb(Number(2, s[i]));
                i++;
            }
            else if (isdigit(s[i])) {
                int val = 0;
                while (i < n && isdigit(s[i]))
                    val = val * 10 + s[i++] - 48;
                a.pb(Number(0, val));
            }
            else i++;
        }

        vector<Number> hau;
        stack<Number> st;
        rep(i, a.size()) {
            if (a[i].op == -1) {
                hau.pb(a[i]);
            }
            else if (a[i].ch == '(') st.push(a[i]);
            else if (a[i].ch == ')') {
                while (!st.empty() && st.top().ch != '(') {
                    hau.pb(st.top());
                    st.pop();
                }
                if (st.size()) st.pop();
            }
            else {
                while (!st.empty() && a[i].op <= st.top().op) {
                    hau.pb(st.top());
                    st.pop();
                }
                st.push(a[i]);
            }
        }
        while (!st.empty()) {
            hau.pb(st.top());
            st.pop();
        }
        
        st = stack<Number>();
        rep(i, hau.size()) {
            if (hau[i].op == -1) st.push(hau[i]);
            else {
                Number y = st.top(); st.pop();
                Number x = st.top(); st.pop();
                st.push(x.compute(y, hau[i]));
            }
        }
        if (caseno) puts("");
        printf("Equation #%d\n", ++caseno);
        int aa = st.top().a;
        int bb = st.top().b;
        if (!aa && bb) puts("No solution.");
        else if (!aa && !bb)
            puts("Infinitely many solutions.");
        else {
            double xx = -bb / (double)aa;
            printf("x = %.6lf\n", xx);
        }
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
