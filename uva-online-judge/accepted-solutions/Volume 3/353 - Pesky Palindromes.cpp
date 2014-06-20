/*****************/
/* LAM PHAN VIET */
/* UVa: 353 - Pesky Palindromes
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

map <string, int> Free;
int dem, n;

void Check(string s1) {
    string s2(s1);
    reverse(s2.begin(), s2.end());
    if (s1==s2 && !Free[s1]) {
        dem++; Free[s1] = 1;
    }
}

main() {
    int len, i;
    string str;
    while (cin >> str) {
        n = str.length();
        len = 1; dem = 0;
        while (len<=n) {
            i = 0;
            while (i+len<=n) {
                string temp(str,i,len);
                Check(temp);
                i++;
            }
            if (i<n) {
                string temp(str,i,n-i);
                Check(temp);
            }
            len++;
        }
        cout << "The string '" << str << "' contains "<< dem << " palindromes." << endl;
        Free.clear();
    }
}
