//============================
// Author: lamphanviet@gmail.com
// Problem: 11639 - Guard the Land
//============================
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <deque>

using namespace std;

#define fr(i,a,b) for (int i = (a); i <= (b); i++)
#define frr(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define int64 long long
#define uint64 unsigned long long

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

#define INF 1000111222
#define maxN 111

const int m = 100;
const int n = 2;

int d[maxN][maxN], xx[3];

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int  cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        fill(d, 0);
        int x1, y1, x2, y2;
        rep(i, 2) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            fr(x, x1, x2 - 1) fr(y, y1, y2 - 1)
                d[x][y]++;
        }
        fill(xx, 0);
        fr(i, 0, 99) fr(j, 0, 99)
            xx[d[i][j]]++;
        printf("Night %d:", ++caseNo);
        repr(i, 3) printf(" %d", xx[i]); puts("");
    }
    return 0;
}
