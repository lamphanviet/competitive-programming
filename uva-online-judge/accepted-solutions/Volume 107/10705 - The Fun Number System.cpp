//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10705 - The Fun Number System
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
#define maxN 70
#define MIN -9223372036854775807LL

int k;
int64 n;
uint64 pw[maxN];
string s;
char res[maxN];
bool mark[maxN], solved;

void backTrack(int x, int64 val) {
    if (solved) return;
    if (x == k) {
        if (val == n) solved = true;
        return;
    }
    int64 mn = val, mx = val;
    fr(i, x, k - 1)
        if (s[i] == 'n')
            mn -= pw[k - i - 1];
        else if (s[i] == 'p')
            mx += pw[k - i - 1];
    if (n < mn || mx < n) return;
    
    int64 add = pw[k - x - 1];
    if (s[x] == 'n') add = -add;
    res[x] = 1 + '0';
    backTrack(x + 1, val + add);
    if (solved) return;
    res[x] = 0 + '0';
    backTrack(x + 1, val);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    pw[0] = 1LL;
    fr(i, 1, 63) pw[i] = pw[i - 1] * 2LL;
    int cases;
    for (scanf("%d", &cases); cases--; ) {
        scanf(" %d ", &k);
        cin >> s >> n;
        fill(mark, false);
        solved = false;
        if (n < MIN) {
            if (k == 64 && s[0] == 'n') {
                rep(i, k) res[i] = '0';
                res[0] = '1';
                solved = true;
            }
        }
        else backTrack(0, 0LL);
        if (!solved) puts("Impossible");
        else {
            rep(i, k) putchar(res[i]);
            puts("");
        }
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
