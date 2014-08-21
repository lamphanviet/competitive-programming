//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVA
// Problem Name : 12342 - Tax Calculator
// Time Limit   : 1.000s
// Description  :
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

int maxValue[] = { 180000, 300000, 400000, 300000 };
double percent[] = { 0, 0.1, 0.15, 0.20 };

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    double tax;
    int Case, income;
    scanf("%d", &Case);
    FOR (test, 1, Case) {
        scanf("%d", &income);
        tax = 0;
        for (int i = 0; i < 4 && income; i++) {
            int cost = min(income, maxValue[i]);
            tax += cost * percent[i];
            income -= cost;
        }
        if (income) tax += income * 0.25;
        if (tax && tax < 2000) tax = 2000;
        printf("Case %d: %d\n", test, (int)ceil(tax));
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
