//*****************
// LAM PHAN VIET **
// UVA 10140 - Prime Distance
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 46500
using namespace std;

long np, L, R;
bool isP[maxN];
vector<int> prime;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
    np = prime.size();
}

bool isPrime(int n) {
    if (n<maxN) return isP[n];
    for (int i=0, lm=(int)sqrt(n); i<np && prime[i]<=lm; i++)
        if (n%prime[i]==0) return false;
    return true;
}

int nextPrime(long long u) {
    for (++u; u<=R; u++)
        if (isPrime(u)) return (int)u;
    return -1;
}

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    while (scanf("%ld %ld", &L, &R)!=EOF) {
        int Max = 0, Min = INF, ax, ay, bx, by;
        int last = nextPrime(L-1), next;
        if (last!=-1) while (1) {
            next = nextPrime(last);
            if (next==-1) break;
            if (next-last > Max) {
                Max = next - last;
                ax = last; ay = next;
            }
            if (next-last < Min) {
                Min = next - last;
                bx = last; by = next;
            }
            last = next;
        }
        if (Max==0) puts("There are no adjacent primes.");
        else printf("%d,%d are closest, %d,%d are most distant.\n", bx, by, ax, ay);
    }
}

/* lamphanviet@gmail.com - 2011 */
