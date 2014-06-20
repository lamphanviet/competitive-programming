//*****************
// LAM PHAN VIET **
// UVA 10895 - Matrix Transpose
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10001
using namespace std;

class Element {
public:
    int p, val;
    Element(int pp, int v) {
        p = pp; val = v;
    }
};
int n, m, p[maxN];
vector<Element> matrix[maxN];

bool cmp(Element a, Element b) {
    return (a.p < b.p);
}

main() {
//    FileIn("test"); FileOut("test");
    int k, val;
    while (scanf("%d %d", &n, &m)!=EOF) {
        FOR (i, 1, m) matrix[i].clear();
        
        FOR (i, 1, n) {
            scanf("%d", &k);
            REP(j, k) scanf("%d", &p[j]);
            REP(j, k) {
                scanf("%d", &val);
                matrix[p[j]].pb(Element(i, val));
            }
        }
        
        // output
        printf("%d %d\n", m, n);
        FOR (i, 1, m) {
            int k = matrix[i].size();
            if (!k) {
                printf("0\n\n");
                continue;
            }
            printf("%d", k);
            sort(all(matrix[i]), cmp);
            REP(j, k) printf(" %d", matrix[i][j].p);
            printf("\n%d", matrix[i][0].val);
            FOR (j, 1, k-1) printf(" %d", matrix[i][j].val);
            printf("\n");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
