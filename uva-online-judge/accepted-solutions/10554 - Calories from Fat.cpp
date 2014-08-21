//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10554 - Calories from Fat
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
#define maxN 5

const int x[] = { 9, 4, 4, 4, 7 };
double a[maxN];
char c[maxN], s[maxN];
double sum[maxN], cal[maxN];

void compute() {
    double C = 0.0, per = 0.0;
    rep(i, maxN)
        if (c[i] == '%') {
            per += a[i];
        }
        else if (c[i] == 'C') {
            cal[i] = a[i];
            C += cal[i];
        }
        else if (c[i] == 'g') {
            cal[i] = a[i] * x[i];
            C += cal[i];
        }
    double one = C / (100.0 - per);
    rep(i, maxN) if (c[i] == '%')
        cal[i] = one * a[i];
    //rep(i, maxN) printf("");
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	while (scanf(" %s ", s) != EOF) {
        if (strcmp(s, "-") == 0) break;
        rep(i, maxN) sum[i] = cal[i] = 0;
        do {
            rep(i, maxN) cal[i] = 0;
            sscanf(s, " %lf%c ", &a[0], &c[0]);
            fr(i, 1, maxN - 1) scanf(" %lf%c ", &a[i], &c[i]);
            //rep(i, maxN) printf("");
            compute();
            rep(i, maxN) sum[i] += cal[i];
            scanf(" %s ", s);
        } while (strcmp(s, "-") != 0);
        double all = 0.0;
        rep(i, maxN) all += sum[i];
        all = sum[0] / all * 100.0;
        //printf("res %.10lf\n", all);
        int res = (int)all;
        if (all >= (double)res + 0.5) res++;
        printf("%d%%\n", res);
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
