//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: 3.000s
// Problem: 1223 - Editor
// Time limit: 3.000s
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
#define maxN 5005
#define maxLN 17
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Entry {
    int p;
    ii value;
    bool operator < (const Entry &e) const { return value < e.value; }
} L[maxN];
int n, P[maxLN][maxN], Log;
char s[maxN];

void buildSuffixArray() {
    REP(i, n) P[0][i] = s[i] - 'a';
    int len = 1;
    bool stop = false;
    for (Log = 1; len < n; Log++, len <<= 1) {
        REP(i, n) {
            L[i].value.ff = P[Log - 1][i];
            L[i].value.ss = (i + len < n) ? P[Log - 1][i + len] : -1;
            L[i].p = i;
        }
        sort(L, L + n);
        P[Log][L[0].p] = 0;
        stop = true;
        for (int i = 1; i < n; i++)
            if (L[i].value == L[i - 1].value) {
                P[Log][L[i].p] = P[Log][L[i - 1].p];
                stop = false;
            }
            else P[Log][L[i].p] = i;
        if (stop) break;
    }
    if (stop) {
        for (++Log, len <<= 1; len < n; Log++, len <<= 1)
            REP(i, n) P[Log][i] = P[Log - 1][i];
    }
}

int lcp(int x, int y) {
    int res = 0;
    for (int i = Log - 1; i >= 0 && x < n && y < n; i--)
        if (P[i][x] == P[i][y]) {
            int add = bit(i);
            x += add, y += add, res += add;
        }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        n = strlen(s);
        buildSuffixArray();
        int res = 0;
        for (int i = 1; i < n; i++)
            res = max(res, lcp(L[i - 1].p, L[i].p));
        printf("%d\n", res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
