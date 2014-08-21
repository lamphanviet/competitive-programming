/*****************/
/* LAM PHAN VIET */
/* UVA 10203 - Snow Clearing
/* Time limit: 3.000s
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
#define maxN 10000
using namespace std;

char buff[maxN];
double sum;

double get_distance(int x1, int y1, int x2, int y2) {
    x1 -= x2, y1 -= y2;
    return sqrt(x1 * x1 + y1 * y1);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, a[10];
    for (scanf(" %d ", &Case); Case--; ) {
        sum = 0;
        gets(buff);
        while (gets(buff)) {
            int len = strlen(buff), k = 0, n = 0;
            if (!len) break;
            while (k < len)
                if (buff[k] != ' ') {
                    int value = 0, sign = 1;
                    if (buff[k] == '-')
                        sign = -1, k++;
                    while (k < len && buff[k] != ' ')
                        value = value * 10 + (buff[k++] - 48);
                    a[n++] = value * sign;
                }
                else k++;
            sum += get_distance(a[0], a[1], a[2], a[3]) * 2.0;
        }
        sum *= 3.0;     // sum = sum / 20 * 60
        sum /= 1000.0;
        if (sum - (int)sum >= 0.5) sum++;
        int h = (int)sum / 60, m = (int)sum % 60;
        printf("%d:", h);
        if (m < 10) putchar('0');
        printf("%d\n", m);
        
        if (Case) putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
