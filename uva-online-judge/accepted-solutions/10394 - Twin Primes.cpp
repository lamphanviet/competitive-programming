/*****************/
/* LAM PHAN VIET */
/* UVA 10394 - Twin Primes
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 18409205
#define maxQ 1000010
using namespace std;

int res[maxQ], n, k, len;
char buff[10];

void sieve_precal() {
    bitset<maxN> isP;
    n = 0;
    for (int i = 3; i <= 4290; i += 2)
        if (!isP[i]) {
            for (int j = i * i; j < maxN; j += i + i)
                isP.set(j);
            if (!isP[i + 2])
                res[++n] = i;
        }
    int m = 4337, tmp = maxN - 2;
    while (m + 2 < tmp) {
        if (!isP[m] && !isP[m + 2])
            res[++n] = m;
        m += 2;
    }
}

void print(int n) {
    k = 0;
    while (n) {
        buff[k++] = n % 10 + 48;
        n /= 10;
    }
    while (k > 0) putchar(buff[--k]);
}

main() {
//    FileIn("test"); FileOut("test");
    sieve_precal();
    while (gets(buff)) {
        len = strlen(buff);
        n = k = 0;
        while (k < len && buff[k] != ' ')
            n = n * 10 + buff[k++] - 48;
        putchar('('); print(res[n]);
        putchar(','); putchar(' ');
        print(res[n] + 2); putchar(')');
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
