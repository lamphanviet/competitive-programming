//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 135 - No Rectangles
// Time Limit   : .000s
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define N 135
int mark[N][N];
int col[N], row[N];
bool isRec(int x, int y) {
    for (int i=x-1;i>=1;i--)
        for (int j=y-1;j>=1;j--)
            if (mark[i][j] && mark[i][y] && mark[x][j]) return false;
    //cout<<x<<" "<<y<<endl;
    return true;
}
int main() {
	#ifndef ONLINE_JUDGE
	//freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int k = 4, n = 13;
	memset(mark, 0, sizeof(mark));
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	
	for (int i=1;i<=n;i++) {
	    for (int j=1;j<=n;j++) {
            if (isRec(i, j) && row[i] < k && col[j] < k) {
                mark[i][j] = 1;
                row[i]++;
                col[j]++;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            cout<<mark[i][j]<<" ";
            cout<<endl;
    }
    int space;
    for (int i=1;i<=n;i++) {
        space = 0;
        for (int j=1;j<=n;j++) {
            if (mark[i][j]) {
                if (space) printf(" ");
                space = 1;
                printf("%d",j);
            }
        }
        printf("\n");
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
