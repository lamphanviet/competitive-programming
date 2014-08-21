//*****************
// LAM PHAN VIET **
// UVA 516 - Prime Land
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
#define maxN 1000001
using namespace std;

bool isP[maxN];
vector<int> prime;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3, lm=(int)sqrt(maxN); i<=lm; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

void Solve(int n) {
    vector<int> num, t;
    int p = 0, np = prime.size();
    while (p<np && n>1) {
        if (n%prime[p]==0) {
            int Count = 0;
            while (n>1 && n%prime[p]==0) {
                n /= prime[p];
                Count++;
            }
            num.pb(prime[p]);
            t.pb(Count);
        }
        p++;
    }
    n = num.size();
    if (n) printf("%d %d", num[n-1], t[n-1]);
    for (int i=n-2; i>=0; i--)
        printf(" %d %d", num[i], t[i]);
    printf("\n");
}

int Power(int n, int k) {
    if (k==1) return n;
    int tmp = Power(n, k/2);
    if (k%2) return tmp*tmp*n;
    return tmp*tmp;
}

main() {
  //  FileIn("test"); FileOut("test");
    Sieve();
    char s[1000];
    while (gets(s)) {
        int len = strlen(s), k = 0, a, b, n = 1;
        if (len==1 && s[0]=='0') break;
        while (k<len) {
            while (k<len && s[k]==' ') k++;
            if (k<len) {
                sscanf(s+k, "%d", &a);
                while (k<len && s[k]!=' ') k++;
                while (k<len && s[k]==' ') k++;
                if (k<len) {
                    sscanf(s+k, "%d", &b);
                    n *= Power(a, b);
                    while (k<len && s[k]!=' ') k++;
                }
            }
        }
        Solve(n-1);
    }
}

/* lamphanviet@gmail.com - 2011 */
