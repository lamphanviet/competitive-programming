//*****************
// LAM PHAN VIET **
// UVA 962 - Taxicab Numbers
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
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 1001
#define maxM 1000100000
using namespace std;

int Mu3[maxN], Sum[441600];
vector<int> num;
vector<int>::iterator low, high;

void PreCalc() {
    REP (i, 1, 1000) Mu3[i] = i*i*i;
    int m = 0;
    REP (i, 1, 1000)
        REP (j, i, 1000)
            if (Mu3[i] + Mu3[j] <= maxM)
                Sum[++m] = Mu3[i] + Mu3[j];
    sort(Sum+1, Sum+m+1);
    int dem = 1;
    REP (i, 2, m)
        if (Sum[i]!=Sum[i-1]) {
            if (dem>1) num.pb(Sum[i-1]);
            dem = 1;
        }
        else dem++;
    if (dem>1) num.pb(Sum[m]);
}

main() {
 //   FileIn("test"); FileOut("test");
    PreCalc();
    int a, b;
    while (scanf("%d %d", &a, &b)!=EOF) {
        low = lower_bound(all(num), a);
        high = upper_bound(all(num), a+b);
        bool f = true;
        for (; low!=high; low++) {
            printf("%d\n", *low);
            f = false;
        }
        if (f) puts("None");
    }
}

/* lamphanviet@gmail.com - 2011 */
