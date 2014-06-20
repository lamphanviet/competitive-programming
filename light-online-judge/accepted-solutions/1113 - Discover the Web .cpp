//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1113 - Discover the Web
// Time Limit   : 1.000s
// Description  : beginner
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 100010
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

stack<string> bw;
stack<string> fw;

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp");// outFile("test.out");
    #endif
    string cur, read;
    int caseNo, cases = 0;
    scanf("%d ", &caseNo);
    while (caseNo--) {
        printf("Case %d:\n", ++cases);
        bw = stack<string>();
        fw = stack<string>();
        cur = "http://www.lightoj.com/";
        while (cin >> read) {
            if (read == "QUIT") break;
            if (read == "VISIT") {
                cin >> read;
                bw.push(cur);
                cur = read;
                fw = stack<string>();
            }
            else if (read == "BACK") {
                if (!bw.size()) {
                    puts("Ignored");
                    continue;
                }
                fw.push(cur);
                cur = bw.top();
                bw.pop();
            }
            else if (read == "FORWARD") {
                if (!fw.size()) {
                    puts("Ignored");
                    continue;
                }
                bw.push(cur);
                cur = fw.top();
                fw.pop();
            }
            cout << cur << endl;
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011

