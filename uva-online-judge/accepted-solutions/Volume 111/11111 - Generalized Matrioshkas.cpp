//*****************
// LAM PHAN VIET **
// UVA 11111 - Generalized Matrioshkas
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
#include <stack>
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
#define maxN 1000000
using namespace std;

char s[maxN];
int doll[maxN], sum[maxN], top = 0;

bool process(int val) {
    if (val < 0) {
        doll[++top] = -val;
        sum[top] = 0;
        return true;
    }
    
    if (!top || doll[top] != val) return false;
    if (sum[top] >= val) return false;
    sum[top-1] += val;
    top--;
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        top = 0;
        int n = strlen(s), k = 0, val;
        bool res = true;
        while (k < n) {
            while (k < n && s[k]==' ') k++;
            if (k < n) {
                sscanf(s + k, "%d", &val);
                res = process(val);
                if (!res) break;
                while (k < n && s[k]!=' ') k++;
            }
        }
        if (top) res = false;
        if (res) puts(":-) Matrioshka!");
        else puts(":-( Try again.");
    }
}

/* lamphanviet@gmail.com - 2011 */
