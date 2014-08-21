//*****************
// LAM PHAN VIET **
// UVA 11408 - Count DePrimes
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
#define maxN 5000001
using namespace std;

bool isP[maxN];
int Sum[maxN], Num[maxN];

void PreCal() {
    REP (i, maxN) {
        isP[i] = true;
        Sum[i] = 0;
    }
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) {
        isP[i] = false;
        Sum[i] += 2;
    }
    for (int i=3, lm=maxN/2; i<=lm; i+=2)
        if (isP[i]) {
            Sum[i] += i;
            for (int j=i+i; j<maxN; j+=i) {
                isP[j] = false;
                Sum[j] += i;
            }
        }
    for (int i=maxN/2; i<maxN; i++)
        if (isP[i]) Sum[i] += i;
    Sum[2] += 2;
    Num[0] = 0;
    for (int i=1; i<maxN; i++)
        if (isP[Sum[i]]) Num[i] = Num[i-1]+1;
        else Num[i] = Num[i-1];
}

main() {
//    FileIn("test"); FileOut("test");
    PreCal();
    int n, m;
    while (scanf("%d", &n)==1 && n) {
        scanf("%d", &m);
        int ans = Num[m] - Num[n-1];
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
