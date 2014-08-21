//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12299 - RMQ with Shifts
// Time limit: 2.000s
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

int n, a[maxN], tree[maxN * 6], result;

int ar[50], m;
char buff[maxN];
bool readArray() {
    gets(buff);
    int len = strlen(buff), i = 5;
    m = 0;
    while (i < len && buff[i] != ')') {
        i++;
        ar[m] = 0;
        while (isdigit(buff[i]))
            ar[m] = ar[m] * 10 + buff[i++] - 48;
        m++;
    }
    return (buff[0] == 'q');
}

void get(int p, int L, int R, int U, int V) {
    if (R < U || V < L) return;
    if (U <= L && R <= V) {
        result = min(result, tree[p]);
        return;
    }
    if (L == R) return;
    int c = p << 1, mid = (L + R) >> 1;
    get(c, L, mid, U, V);
    get(c + 1, mid + 1, R, U, V);
}

void update(int p, int L, int R, int U, int value) {
    if (U < L || R < U) return;
    if (L == R) {
        tree[p] = value;
        a[L] = value;
        return;
    }
    int c = p << 1, mid = (L + R) >> 1;
    update(c, L, mid, U, value);
    update(c + 1, mid + 1, R, U, value);
    tree[p] = min(tree[c], tree[c + 1]);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int q, tmp = maxN * 6;
    REP(i, tmp) tree[i] = INF;
    scanf("%d %d", &n, &q);
    FOR (i, 1, n) {
        scanf("%d ", &a[i]);
        update(1, 1, n, i, a[i]);
    }
    while (q--) {
        if (readArray()) { // query
            result = INF;
            get(1, 1, n, ar[0], ar[1]);
            printf("%d\n", result);
        }
        else {  // shift - update
            if (m <= 1) continue;
            int tmp = a[ar[0]];
            for (int i = 0; i < m - 1; i++) {
                update(1, 1, n, ar[i], a[ar[i + 1]]);
            }
            update(1, 1, n, ar[m - 1], tmp);
        }
  //      REP(i, m) printf("%d ", ar[i]); puts("");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
