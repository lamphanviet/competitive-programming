//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12356 - Army Buddies
// Time Limit   : 1.000s
// Description  : BIT - binary search O(nlog^2n)
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
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
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

int n, treeLeft[maxN], treeRight[maxN];

void updateLeft(int i, int value) {
    while (i <= n) {
        treeLeft[i] += value;
        i += Last(i);
    }
}

void updateRight(int i, int value) {
    while (i) {
        treeRight[i] += value;
        i -= Last(i);
    }
}

int getLeft(int i) {
    int res = 0;
    while (i) {
        res += treeLeft[i];
        i -= Last(i);
    }
    return res;
}

int getRight(int i) {
    int res = 0;
    while (i <= n) {
        res += treeRight[i];
        i += Last(i);
    }
    return res;
}

int getAliveLeft(int u) {
    int res = -1, L = 1, R = u - 1, key = getLeft(u);
    if (!key) return -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (getLeft(mid) == key)
            res = mid, R = mid - 1;
        else L = mid + 1;
    }
    return res;
}

int getAliveRight(int u) {
    int res = -1, L = u + 1, R = n, key = getRight(u);
    if (!key) return -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (getRight(mid) == key)
            res = mid, L = mid + 1;
        else R = mid - 1;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int m, l, r;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        FOR (i, 0, n) treeLeft[i] = treeRight[i] = 0;
        FOR (i, 1, n)
            updateLeft(i, 1), updateRight(i, 1);
        while (m--) {
            scanf("%d %d", &l, &r);
       //     printf("ask %d %d\n", l, r);
            FOR (i, l, r) {
                updateLeft(i, -1);
                updateRight(i, -1);
            }
            l = getAliveLeft(l);
            r = getAliveRight(r);
            if (l != -1) printf("%d ", l);
            else printf("* ");
            if (r != -1) printf("%d\n", r);
            else puts("*");
        }
        puts("-");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
