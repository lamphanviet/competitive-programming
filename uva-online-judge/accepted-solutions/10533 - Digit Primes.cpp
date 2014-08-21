/*****************/
/* LAM PHAN VIET */
/* UVA 10533 - Digit Primes
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
#define maxN 1000001
using namespace std;

bitset<maxN> isP;
int res[maxN];

bool isDigitPrime(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    if (sum <= 1) return false;
    if (sum == 2) return true;
    return (!isP[sum] && sum % 2);
}

void sieve() {
    for (int i = 3; i < 1000; i++)
        if (!isP[i])
            for (int j = i * i; j < maxN; j += i + i)
                isP.set(j);
    res[0] = res[1] = 0;
    res[2] = 1;
    for (int i = 3; i < maxN; i += 2) {
        res[i] = res[i-1];
        if (!isP[i] && isDigitPrime(i))
            res[i]++;
        res[i+1] = res[i];
    }
}

int scan() {
    int value = 0;
    char ch;
    while (true) {
        ch = getchar();
        if (ch == '\n' || ch == ' ') break;
        value = value * 10 + ch - 48;
    }
    return value;
}

void print(int n, int m = 0) {
    if (!n) {
        putchar('0'); return;
    }
    char buff[10];
    while (n) {
        buff[m++] = n % 10 + 48;
        n /= 10;
    }
    while (m) putchar(buff[--m]);
}

main() {
//    FileIn("test"); FileOut("test");
    sieve();
    for (int Case = scan(), a, b; Case--; ) {
        a = scan(); b = scan();
        print(res[b] - res[a-1]);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
