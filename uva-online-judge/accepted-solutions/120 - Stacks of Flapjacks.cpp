//*****************
// LAM PHAN VIET **
// UVA 120 - Stacks of Flapjacks
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
#define maxN 35
using namespace std;

int n, a[maxN];
char s[1000];

void ProcessInput() {
    int len = strlen(s), k = 0;
    n = 0;
    while (k < len) {
        while (k < len && s[k]==' ') k++;
        if (k < len) {
            sscanf(s + k, "%d", &a[++n]);
            while (k < len && s[k]!=' ') k++;
        }
    }
    printf("%d", a[1]);
    FOR (i, 2, n) printf(" %d", a[i]);
    printf("\n");
    reverse(a + 1, a + n + 1);
}

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        ProcessInput();
        FOR (i, 1, n-1) {
            int Max = a[i], u = i;
            FOR (j, i+1, n)
                if (a[j] > Max) {
                    Max = a[j]; u = j;
                }
            if (u==i) continue;
            if (u<n) {
                printf("%d ", u);
                reverse(a + u, a + n + 1);
            }
            printf("%d ", i);
            reverse(a + i, a + n + 1);
        }
        puts("0");
    }
}

/* lamphanviet@gmail.com - 2011 */
