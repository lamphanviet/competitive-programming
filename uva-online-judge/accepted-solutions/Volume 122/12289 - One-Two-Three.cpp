//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12289 - One-Two-Three
// Time limit: 1.000s
//=============================//
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
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int Count(string a, string b) {
    int same = 0;
    REP(i, 3)
        if (a[i] == b[i]) same++;
    return same;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case;
    string s;
    for (scanf("%d", &Case); Case--; ) {
        cin >> s;
        if (s.length() == 5) puts("3");
        else {
            if (Count(s, "one") >= 2) puts("1");
            else puts("2");
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
