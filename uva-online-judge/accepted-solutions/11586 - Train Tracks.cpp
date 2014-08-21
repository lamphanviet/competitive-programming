/*****************/
/* LAM PHAN VIET */
/* UVA 11586 - Train Tracks
/* Time limit: 1.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
#define maxN 55
using namespace std;

vector<string> s;
char buff[maxN * 5];

void read_line() {
    s.clear();
    gets(buff);
    int len = strlen(buff), i = 0;
    while (i < len)
        if (buff[i] != ' ') {
            string tmp = "";
            while (buff[i] != ' ')
                tmp += buff[i++];
            s.pb(tmp);
        }
        else i++;
}

bool solve() {
    if (s.size() == 1) return false;
    int in_f = 0, out_f = 0;
    int in_m = 0, out_m = 0;
    REP(i, s.size()) {
        if (s[i][0] == 'F') in_f++;
        else in_m++;
        if (s[i][1] == 'F') out_f++;
        else out_m++;
    }
    return (in_f == out_m && in_m == out_f);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        read_line();
        if (solve()) puts("LOOP");
        else puts("NO LOOP");
    }
}

/* lamphanviet@gmail.com - 2011 */
