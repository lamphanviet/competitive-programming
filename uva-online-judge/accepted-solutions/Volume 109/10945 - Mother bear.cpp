/*****************/
/* LAM PHAN VIET */
/* UVa: 10945 - Mother bear
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

char s[maxN];

bool is_palind() {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        while (!isalpha(s[i]) && i < j) i++;
        while (!isalpha(s[j]) && i < j) j--;
        if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        i++, j--;
    }
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        if (strcmp(s, "DONE") == 0) break;
        if (is_palind()) puts("You won't be eaten!");
        else puts("Uh oh..");
    }
}

/* lamphanviet@gmail.com - 2011 */
