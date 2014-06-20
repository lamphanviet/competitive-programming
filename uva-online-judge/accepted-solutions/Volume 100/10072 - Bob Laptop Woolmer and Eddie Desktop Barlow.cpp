//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10072 - Bob Laptop Woolmer and Eddie Desktop Barlow
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
#define maxN 111

int n, x, y, z;
int fx[maxN], fy[maxN], fz[maxN];
int f[maxN][8][6][5], trace[maxN][8][6][5];
vi resX, resY, resZ;
bool okX[maxN], okY[maxN], okZ[maxN];

int nearest(double k) {
    int res = (int)k;
    if (k - res >= 0.5 - eps) res++;
    return res;
}

void findResult() {
    resX.clear(); resY.clear(); resZ.clear();
    while (n) {
        int k = trace[n][x][y][z];
        if (k == 1) {
            resX.pb(n); x--;
        }
        else if (k == 2) {
            resY.pb(n); y--;
        }
        else if (k == 3) {
            resZ.pb(n); z--;
        }
        n--;
    }
    sort(all(resX));
    sort(all(resY));
    sort(all(resZ));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int caseNo = 0, bat, bow, fd;
    while (scanf("%d", &n) && n) {
        fr(i, 1, n) {
            scanf("%d %d %d", &bat, &bow, &fd);
            fx[i] = nearest(0.8 * bat + 0.2 * fd);
            fy[i] = nearest(0.7 * bow + 0.1 * bat + 0.2 * fd);
            fz[i] = nearest(0.4 * bat + 0.4 * bow + 0.2 * fd);
            okX[i] = bat && fd;
            okY[i] = bow && (bat || fd);
            okZ[i] = bow && bat && fd;
        }
        scanf("%d %d %d", &x, &y, &z);
        
        fill(f, 0);
        fr(i, 1, n) {
            fr(xx, 0, x + 1) fr(yy, 0, y + 1) fr(zz, 0, z + 1) {
                int &cur = f[i][xx][yy][zz];
                trace[i][xx][yy][zz] = 0;
                cur = f[i - 1][xx][yy][zz];
                if (xx > 0 && okX[i]) {
                    int next = f[i - 1][xx - 1][yy][zz] + fx[i];
                    if (next > cur) {
                        cur = next;
                        trace[i][xx][yy][zz] = 1;
                    }
                }
                if (yy > 0 && okY[i]) {
                    int next = f[i - 1][xx][yy - 1][zz] + fy[i];
                    if (next > cur) {
                        cur = next;
                        trace[i][xx][yy][zz] = 2;
                    }
                }
                if (zz > 0 && okZ[i]) {
                    int next = f[i - 1][xx][yy][zz - 1] + fz[i];
                    if (next > cur) {
                        cur = next;
                        trace[i][xx][yy][zz] = 3;
                    }
                }
            }
        }
        
        int res = f[n][x][y][z];
        findResult();
        if (caseNo) puts("");
        printf("Team #%d\n", ++caseNo);
        printf("Maximum Effective Score = %d\n", res);
        printf("Batsmen : ");
        rep(i, resX.size() - 1) printf("%d ", resX[i]);
        if (resX.size()) printf("%d", resX.back());
        puts("");
        printf("Bowlers : ");
        rep(i, resY.size() - 1) printf("%d ", resY[i]);
        if (resY.size()) printf("%d", resY.back());
        puts("");
        printf("All-rounders : ");
        rep(i, resZ.size() - 1) printf("%d ", resZ[i]);
        if (resZ.size()) printf("%d", resZ.back());
        puts("");
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
