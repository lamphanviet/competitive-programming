//*****************
// LAM PHAN VIET **
// UVA 10420 - List of Conquests
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
#define maxN 80
using namespace std;

map<string, int> women_count;

main() {
//    FileIn("test"); FileOut("test");
    int n;
    char country[maxN], name[maxN];
    scanf("%d ", &n);
    while (n--) {
        scanf(" %s ", &country);
        gets(name);
        women_count[country]++;
    }
    map<string, int>::iterator it = women_count.begin();
    while (it != women_count.end()) {
        cout << it->first;
        printf(" %d\n", it->second);
        it++;
    }
}

/* lamphanviet@gmail.com - 2011 */
