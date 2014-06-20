//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 555 - Bridge Hands
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
#define maxN 55

pair<char, char> card[maxN];
char name[] = { 'S', 'W', 'N', 'E' };
pair<char, char> p[4][maxN];
map<char, int> idx;
int n, np[4];
char s[maxN * 3];
int rank[300], suit[300];

bool cmp(pair<char, char> a, pair<char, char> b) {
    if (suit[a.ff] == suit[b.ff])
        return rank[a.ss] < rank[b.ss];
    return suit[a.ff] < suit[b.ff];
}

void parse() {
    int m = strlen(s);
    for (int i = 0; i < m; i += 2)
        card[n++] = mp(s[i], s[i + 1]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    rep(i, 4) idx[name[i]] = i;
    suit['C'] = 0; suit['D'] = 1; suit['S'] = 2; suit['H'] = 3;
    fr(i, 2, 9) rank[i + '0'] = i;
    rank['T'] = 10; rank['J'] = 11;
    rank['Q'] = 12; rank['K'] = 13; rank['A'] = 14;
    char k;
    while (scanf(" %c ", &k) != EOF) {
        if (k == '#') break;
        k = idx[k]; n = 0;
        k = (k + 1) % 4;
        gets(s); parse();
        gets(s); parse();
        rep(i, 4) np[i] = 0;
        rep(i, n) {
            p[k][np[k]++] = card[i];
            k = (k + 1) % 4;
        }
        rep(i, 4) {
            printf("%c:", name[i]);
            sort(p[i], p[i] + np[i], cmp);
            rep(j, np[i]) printf(" %c%c", p[i][j].ff, p[i][j].ss);
            puts("");
        }
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
