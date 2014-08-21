//*****************
// LAM PHAN VIET **
// UVA 118 - Mutant Flatworld Explorers
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
#define maxN 55
using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
int n, m, k, fx, fy, len;
bool lost[maxN][maxN];
char s[105];

bool Move(int i, int x, int y, int kk) {
    fx = x; fy = y; k = kk;
    if (i==len) return true;
    if (s[i]=='R') return Move(i+1, x, y, (kk+1)%4);
    else if (s[i]=='L') return Move(i+1, x, y, (kk+3)%4);
    else {
        int xx = x + dx[kk], yy = y + dy[kk];
        if (xx<0 || xx>n || yy<0 || yy>m) {
            if (lost[x][y]) return Move(i+1, x, y, kk);
            else {
                lost[x][y] = true;
                return false;
            }
        }
        return Move(i+1, x + dx[kk], y + dy[kk], kk);
    }
}

main() {
//    FileIn("test"); FileOut("test");
    scanf("%d %d", &n, &m);
    Fill(lost, false);
    int sx, sy;
    char ch;
    while (scanf("%d %d", &fx, &fy)!=EOF) {
        scanf(" %c %s", &ch, &s);
        len = strlen(s);
        
        if (ch=='N') k = 0;
        else if (ch=='E') k = 1;
        else if (ch=='S') k = 2;
        else k = 3;
        bool ok = Move(0, fx, fy, k);
        
        printf("%d %d ", fx, fy);
        if (k==0) printf("N");
        else if (k==1) printf("E");
        else if (k==2) printf("S");
        else printf("W");
        if (!ok) printf(" LOST");
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
