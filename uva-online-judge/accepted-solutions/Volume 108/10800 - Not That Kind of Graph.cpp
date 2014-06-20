//*****************
// LAM PHAN VIET **
// UVA 10800 - Not That Kind of Graph
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
#define maxN 102
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int Case, MaxLen, n;
    char s[maxN], rs[maxN][maxN];
    scanf("%d", &Case); gets(s);
    FOR (kk, 1, Case) {
        gets(s); n = strlen(s);
        Fill(rs, ' ');
        // solve
        
        int x = 50;
        REP (j, n)
            if (s[j]=='R') {
                if (j>0 && s[j-1]=='R') x--;
                rs[x][j] = '/';
            }
            else if (s[j]=='C') {
                if (j>0 && s[j-1]=='R') x--;
                rs[x][j] = '_';
            }
            else {
                if (j>0 && s[j-1]!='R') x++;
                rs[x][j] = '\\';
            }
        
        // print result
        printf("Case #%d:\n", kk);
        bool f = false;
        MaxLen = 0;
        REP (i, maxN) {
            int j = maxN-1;
            while (j>=0 && rs[i][j]==' ') j--;
            if (j<0) {
                if (f) break;
                continue;
            }
            MaxLen = max(MaxLen, j+1);
            rs[i][j+1] = '\0';
            printf("| ");
            puts(rs[i]);
            f = true;
        }
        
        printf("+");
        REP(i, MaxLen+1) printf("-");
        printf("-\n\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
