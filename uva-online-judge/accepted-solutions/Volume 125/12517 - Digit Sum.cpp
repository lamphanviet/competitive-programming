
//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 25
int a[maxN], b[maxN], c[maxN], d[maxN];
int x, y;
int64 findDigit(int pos, int value) {
    for (int i = 1;i <= 11;i++) {
        c[i] = a[i];
        d[i] = b[i];
    }
    if (c[pos] != value) {
        c[pos] = value;
        for (int i = pos + 1;i <= 11;i++) c[i] = 9;
        if (c[pos] > a[pos]) c[pos - 1]--;
    }
    if (d[pos] != value) {
        d[pos] = value;
        for (int i = pos + 1;i <= 11;i++) d[i] = 0;
        if (d[pos] < b[pos]) d[pos - 1]++;
    }
    int64 s1, s2;
    s1 = s2 = 0;
    for (int i = 1;i <= 11;i++)
        if (i != pos) {
            s1 = s1 * 10 + c[i];
            s2 = s2 * 10 + d[i];
        }
    if (s1 < s2) return 0;
    return (s1 - s2 + 1);
}
int64 solve() {
    int64 res = 0;
    for (int i = 11;i>=1;i--) {
        a[i] = x % 10;
        b[i] = y % 10;
        x/=10; y/=10;        
    }
    for (int i = 1; i <= 9;i++)
        for (int j = 2;j <= 11;j++)
            res += i * findDigit(j, i);
    return res;
}
int main() {
	/*#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif*/
	while ( scanf("%d %d", &x, &y) && (x + y)){
	    swap(x, y);
	    printf("%lld\n", solve());
	}
	return 0;
}
