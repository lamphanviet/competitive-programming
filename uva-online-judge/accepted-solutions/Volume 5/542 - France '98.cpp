//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 542 - France '98
// Time Limit   : .000s
// Description  : Luong Van Do code
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
map <string, int> mx;
string name[maxN];
double p[maxN][maxN];
double ans[maxN];
double r1[maxN], r2[maxN], r3[maxN];
void findr1() {
    for (int i=1;i<=16;i++)
        if (i % 2 == 1)
            r1[i] = p[i][i + 1];
        else
            r1[i] = p[i][i - 1];
}
void findr2() {
    for (int i=1;i<=16;i++) {
        if (i == 1 || i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 13 || i == 14) {
                if (i % 2 == 1)
                    r2[i] = r1[i] * (r1[i + 2] * p[i][i + 2] + r1[i + 3] * p[i][i + 3]);
                    else
                    r2[i] = r1[i] * (r1[i + 1] * p[i][i + 1] + r1[i + 2] * p[i][i + 2]);
        }
        else
                if (i % 2 == 0)
                    r2[i] = r1[i] * (r1[i - 2] * p[i][i - 2] + r1[i - 3] * p[i][i - 3]);
                    else
                    r2[i] = r1[i] * (r1[i - 1] * p[i][i - 1] + r1[i - 2] * p[i][i - 2]);
    }
}
void findr3() {
    for (int i=1;i<=16;i++) {
        if (i>=1 && i<=8) {
            if (i>=1 && i<=4)
                r3[i] = r2[i] * (r2[5] * p[i][5] + r2[6] * p[i][6] + r2[7] * p[i][7] + r2[8] * p[i][8]);
            else
                r3[i] = r2[i] * (r2[1] * p[i][1] + r2[2] * p[i][2] + r2[3] * p[i][3] + r2[4] * p[i][4]);
        }
        else {
            if (i>=9 && i<=12)
                r3[i] = r2[i] * (r2[13] * p[i][13] + r2[14] * p[i][14] + r2[15] * p[i][15] + r2[16] * p[i][16]);
            else
                r3[i] = r2[i] * (r2[9] * p[i][9] + r2[10] * p[i][10] + r2[11] * p[i][11] + r2[12] * p[i][12]);
        }
    }
}
double solve() {
    for (int i=1;i<=16;i++) ans[i] = 0.0;
    for (int i=1;i<=16;i++)
        if ( i>=1 && i<= 8 ) {
            for (int j=9;j<=16;j++)
                ans[i]+= (r3[j] * p[i][j]);
            ans[i]*=r3[i];
        }
        else {
            for (int j=1;j<=8;j++)
                ans[i]+= (r3[j] * p[i][j]);
            ans[i]*=r3[i];
        }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    mx.clear();
    for (int i=1;i<=16;i++)
        cin >> name[i];
    for (int i=1;i<=16;i++)
        for (int j=1;j<=16;j++) {
            scanf("%lf",&p[i][j]);
            p[i][j]/=100.0;
        }
    /*for (int i=1;i<=16;i++) {
        for (int j=1;j<=16;j++)
            printf("%lf ",p[i][j]);
            puts("");
    }*/
    findr1(); findr2(); findr3();
    solve();
    for (int i=1;i<=16;i++) {
        cout << name[i];
        for (int j=0;j<10 - name[i].length() + 1;j++) printf(" ");
        printf("p=%.2lf%%\n", ans[i] * 100.0);
    }
    return 0; 
}

/* Copyright (C) 2012, LamPhanViet */
