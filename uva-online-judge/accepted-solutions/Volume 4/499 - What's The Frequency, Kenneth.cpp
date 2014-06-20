/*****************/
/* LAM PHAN VIET */
/* UVA 499 - What's The Frequency, Kenneth
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
#define maxN 256
using namespace std;

char s[1001];
int numbers[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        Fill(numbers, 0);
        int len = strlen(s);
        REP(i, len)
            if (isalpha(s[i]))
                numbers[s[i]]++;
        int frequency_max = 0;
        REP(i, maxN)
            if (numbers[i] > frequency_max)
                frequency_max = numbers[i];
        REP(i, maxN)
            if (numbers[i] == frequency_max)
                putchar(i);
        printf(" %d", frequency_max);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
