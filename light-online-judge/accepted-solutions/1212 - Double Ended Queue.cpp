//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1212 - Double Ended Queue 
// Time Limit   : .500s
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    char s[20];
    deque<int> dq;
    int caseNo, cases = 0, val, n, m;
    for (scanf("%d", &caseNo); caseNo--; ) {
        scanf("%d %d ", &n, &m);
        dq.clear();
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf(" %s ", &s);
            if (s[4] == 'L') { // pushLeft
                scanf("%d", &val);
                if (dq.size() == n)
                    puts("The queue is full");
                else {
                    printf("Pushed in left: %d\n", val);
                    dq.push_front(val);
                }
            }
            else if (s[4] == 'R') { // pushRight
                scanf("%d", &val);
                if (dq.size() == n)
                    puts("The queue is full");
                else {
                    printf("Pushed in right: %d\n", val);
                    dq.push_back(val);
                }
            }
            else if (s[3] == 'L') { // popLeft
                if (dq.size() == 0)
                    puts("The queue is empty");
                else {
                    printf("Popped from left: %d\n", dq.front());
                    dq.pop_front();
                }
            }
            else { // popRight
                if (dq.size() == 0)
                    puts("The queue is empty");
                else {
                    printf("Popped from right: %d\n", dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
