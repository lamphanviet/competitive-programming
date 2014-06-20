//*****************
// LAM PHAN VIET **
// UVA 10229 - Modular Fibonacci
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
#define INF 500000000
#define maxN 25
using namespace std;

class Matrix {
public:
    int64 a, b, c, d;
    Matrix() { a = 0; b = c = d = 1; }
    Matrix multi(Matrix m) {
        Matrix res;
        res.a = a*m.a + b*m.c; res.b = a*m.b + b*m.d;
        res.c = c*m.a + d*m.c; res.d = c*m.b + d*m.d;
        return res;
    }
    void modulo(int MOD) {
        a %= MOD; b %= MOD;
        c %= MOD; d %= MOD;
    }
};
int n, m, f[maxN];

Matrix matrix_power(Matrix a, int n) {
    if (n==1) return a;
    Matrix res = matrix_power(a, n / 2);
    res.modulo(m);
    res = res.multi(res);
    res.modulo(m);
    if (n % 2) return res.multi(a);
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    f[0] = 0; f[1] = 1;
    FOR (i, 2, maxN-1)
        f[i] = f[i-2] + f[i-1];
    Matrix tmp = Matrix();
    while (scanf("%d %d", &n, &m)!=EOF) {
        m = bit(m);
        if (n < 5) printf("%d\n", f[n] % m);
        else {
            Matrix res = matrix_power(Matrix(), n-1);
            res.modulo(m);
            printf("%lld\n", res.d);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
