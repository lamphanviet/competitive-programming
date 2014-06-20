//*****************
// LAM PHAN VIET **
// UVA 450 - Little Black Book
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
#define maxN 200
using namespace std;

struct PersonInfo {
    string title, first, last;
    string add, dpm;
    string homephone, workphone, campusbox;
};
int n, k;
char s[maxN];
vector<PersonInfo> res;

bool cmp(PersonInfo a, PersonInfo b) {
    return (a.last < b.last);
}

void PrintResult() {
    sort(all(res), cmp);
    REP (i, res.size()) {
        puts("----------------------------------------");
        cout << res[i].title << " " << res[i].first << " " << res[i].last << endl;
        cout << res[i].add << endl;
        printf("Department: "); cout << res[i].dpm << endl;
        printf("Home Phone: "); cout << res[i].homephone << endl;
        printf("Work Phone: "); cout << res[i].workphone << endl;
        printf("Campus Box: "); cout << res[i].campusbox << endl;
    }
}

string Take() {
    string rs = "";
    while (k < n && s[k]!=',') {
        rs += s[k++];
    }
    k++;
    return rs;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    PersonInfo p;
    char dpm[maxN];
    for (scanf("%d", &Case), gets(dpm); Case--; ) {
        gets(dpm);
        while (gets(s)) {
            n = strlen(s); k = 0;
            if (!n) break;
            
            p.title = Take();
            p.first = Take();
            p.last = Take();
            p.dpm = dpm;
            p.add = Take();
            p.homephone = Take();
            p.workphone = Take();
            p.campusbox = Take();
            
            res.pb(p);
        }
    }
    PrintResult();
}

/* lamphanviet@gmail.com - 2011 */
