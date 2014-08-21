//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10152 - ShellSort
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
#define maxN 211

int n, a[maxN], b[maxN];
string name1[maxN], name2[maxN];
map<string, int> idx;
vector<string> name;
bool mark[maxN];

int getIndex(string s) {
    if (idx.count(s) == 0) {
        name.pb(s);
        int id = idx[s] = name.size() - 1;
        return id;
    }
    return idx[s];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases;
    for (scanf("%d ", &cases); cases--; ) {
        scanf("%d ", &n);
        name.clear(); idx.clear();
        rep(i, n) {
            getline(cin, name1[i]);
            //a[i] = getIndex(name1[i]);
        }
        rep(i, n) {
            getline(cin, name2[i]);
            b[i] = getIndex(name2[i]);
        }
        rep(i, n) a[i] = getIndex(name1[i]);

        //rep(i, n) printf("%d: %d\n", a[i], b[i]); puts("");
        
        vi res;
        fill(mark, false);
        rep(i, n) {
            int u = 0;
            rep(j, n) if (a[j] == i) {
                u = j;
                break;
            }
            mark[u] = true;
            //printf("u %d\n", u);
            int prev = -1, ok = 1;
            rep(j, n) if (!mark[j]) {
                if (a[j] < prev) ok = 0;
                prev = a[j];
            }
            res.pb(i);
            if (ok) {
                if (u == 0) res.pop_back();
                break;
            }
        }
        
        repr(i, res.size())  cout << name[res[i]] << endl;
        puts("");
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
