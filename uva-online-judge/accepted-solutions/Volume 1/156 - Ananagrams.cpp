//*****************
// LAM PHAN VIET **
// UVA 156 - Ananagrams
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
#define maxN 1001
using namespace std;

vector<string> words;
vector<bool> is_relative;
vector<int> res;
int count_char[maxN][30];

bool cmp(int i, int j) {
    return (words[i] < words[j]);
}

main() {
//    FileIn("test"); FileOut("test");
    int n = 0;
    string str = "";
    while (cin >> str) {
        if (str[0]=='#') break;
        words.pb(str);
        REP(i, 26) count_char[n][i] = 0;
        REP(i, str.length())
            count_char[n][tolower(str[i]) - 'a']++;
        is_relative.pb(true);
        n++;
    }
    REP(i, n) {
        if (!is_relative[i]) continue;
        FOR (j, i+1, n-1) {
            bool f = true;
            REP (k, 26)
                if (count_char[i][k] != count_char[j][k]) {
                    f = false;
                    break;
                }
            if (f)
                is_relative[i] = is_relative[j] = false;
        }
        if (is_relative[i]) res.pb(i);
    }
    sort(all(res), cmp);
    REP(i, res.size())
        cout << words[res[i]] << endl;
}

/* lamphanviet@gmail.com - 2011 */
