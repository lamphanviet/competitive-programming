//============================
// Author: lamphanviet@gmail.com
// Problem: 11584 - Partitioning by Palindromes
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
#define maxN 1011

int n, f[maxN];
bool p[maxN][maxN];
char s[maxN];

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int cases;
    for (scanf(" %d ", &cases); cases--; ) {
        scanf(" %s ", s);
        n = strlen(s);
        fill(p, true);
        fr(len, 2, n) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                if (s[i] == s[j]) p[i][j] = p[i + 1][j - 1];
                else p[i][j] = false;
            }
        }
        f[0] = 1;
        fr(i, 1, n - 1) {
            f[i] = INF;
            if (p[0][i]) f[i] = 1;
            else {
                fr(j, 1, i) if (p[j][i]) {
                    f[i] = min(f[i], f[j - 1] + 1);
                }
            }
        }
        printf("%d\n", f[n - 1]);
    }
    return 0;
}
