/*****************/
/* LAM PHAN VIET */
/* UVA 11099 - Next Same-Factored
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
#define maxN 1001
using namespace std;

int prime_size = 168, prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
int res, n;
vector<int> fact;

void factorize(int n) {
    fact.clear();
    int p = 0;
    while(n != 1 && p < prime_size) {
        if (n % prime[p] == 0) {
            fact.pb(prime[p]);
            while (n != 1 && n % prime[p] == 0)
                n /= prime[p];
        }
        p++;
    }
    if (n != 1) fact.pb(n);
}

void back_tracking(int64 m, int i) {
    while (m < res) {
        if (m > n) res = m;
        if (i + 1 < fact.size())
            back_tracking(m, i + 1);
        m *= fact[i];
    }
}

void solve(int n) {
    res = 2000000;
    if (n <= 1) return;
    factorize(n);
    int first = 1;
    REP(i, fact.size()) first *= fact[i];
    res = min((int64)2000000, (int64)(n) * fact[0]);
    back_tracking(first, 0);
}

char buff[10];

bool read(int &value) {
    if (!gets(buff)) return false;
    int len = strlen(buff), i = 0;
    value = 0;
    while (i < len && buff[i] != ' ')
        value = value * 10 + buff[i++] - 48;
    return true;
}

void write(int n) {
    int i = 0;
    while (n) {
        buff[i++] = n % 10 + 48;
        n /= 10;
    }
    while (i > 0) putchar(buff[--i]);
}

main() {
//    FileIn("test"); FileOut("test");
    char str[] = "Not Exist!";
    while (read(n)) {
        solve(n);
        if (res < 2000000)
            write(res);
        else
            REP(i, 10) putchar(str[i]);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
