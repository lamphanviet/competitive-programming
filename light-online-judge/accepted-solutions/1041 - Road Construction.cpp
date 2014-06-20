//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1041 - Road Construction
// Time Limit   : 2.000s
// Description  : MST
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
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 55
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Road {
    int u, v, cost;
    bool operator < (const Road &r) const {
        return cost < r.cost;
    }
} road[maxN];
int n, lab[maxN];
map<string, int> idx;

int getRoot(int v) {
    if (lab[v] < 0) return v;
    lab[v] = getRoot(lab[v]);
    return lab[v];
}

void unionTree(int u, int v) {
    lab[u] = v;
}

int getIndex(string s) {
    int id = idx[s];
    if (!id) id = idx[s] = ++n;
    return id;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char name1[maxN], name2[maxN];
    int caseNo, cases = 0, w, m;
    scanf("%d", &caseNo);
    while (caseNo--) {
        n = 0;
        idx.clear();
        scanf("%d ", &m);
        REP(i, m) {
            scanf("%s %s %d ", &name1, &name2, &w);
            road[i].u = getIndex(name1);
            road[i].v = getIndex(name2);
            road[i].cost = w;
        }
        FOR (i, 1, n) lab[i] = -1;
        sort(road, road + m);
        int cost = 0, counter = 0;
        REP(i, m) {
            if (counter == n - 1) break;
            road[i].u = getRoot(road[i].u);
            road[i].v = getRoot(road[i].v);
            if (road[i].u != road[i].v) {
                cost += road[i].cost;
                counter++;
                unionTree(road[i].u, road[i].v);
            }
        }
        
        printf("Case %d: ", ++cases);
        if (counter == n - 1) printf("%d\n", cost);
        else puts("Impossible");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
