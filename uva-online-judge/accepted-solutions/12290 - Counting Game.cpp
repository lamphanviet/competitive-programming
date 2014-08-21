//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12290 - Counting Game
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
#define maxN 110
#define maxM 2000000
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, k;
bool flag[maxM];

bool check(int n) {
    while (n) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

void precal() {
    REP(i, 7) flag[i] = false;
    for (int i = 7; i < maxM; i++)
        if (i % 7 == 0 || check(i))
            flag[i] = true;
        else flag[i] = false;
}

int solve() {
    int x = 1, Count = 0, p = 1, value = 1;
    while (Count != k) {
        if (flag[x] && p == m) {
            if (++Count == k) return x;
        }
        x++;
        p += value;
        if (p == 0) {
            p = 2;
            value = -value;
        }
        else if (p == n + 1){
            p = n - 1;
            value = -value;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    precal();
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        if (!n && !m && !k) break;
        printf("%d\n", solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
