//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12384 - Span
// Time Limit   : 2.000s
// Description  : prime number - data structure
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
#define maxN 2000010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isP[maxN];
vi prime;

void sieve() {
    fill(isP, true);
    for (int i = 3; i * i < maxN; i += 2)
        if (isP[i]) for (int j = i * i; j < maxN; j += i + i)
            isP[j] = false;
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isP[i]) prime.pb(i);
}

int n, m, a[maxN], f[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    sieve();
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        a[0] = INF; f[0] = 1;
        int sum = 0;
        FOR (i, 1, n) {
            a[i] = prime[i - 1] % m;
            int k = i - 1;
            while (a[i] >= a[k]) {
                k = k - f[k];
            }
            f[i] = i - k;
            sum = (sum + f[i]) % m;
        }
        printf("%d\n", sum % m);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
