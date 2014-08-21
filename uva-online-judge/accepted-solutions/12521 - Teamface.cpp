//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxT 111
#define maxN 5005

int n, size[maxN];
vi f[maxN];
int team, lead[maxT];
char name[maxT][maxT];
bool cnt[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int caseNo = 0, m, id;
	while (scanf("%d %d", &team, &n) && (n | team)) {
	    fill(cnt, false);
	    rep(i, team) scanf(" %s %d ", name[i], &lead[i]);
	    fr(i, 1, n) {
	        scanf("%d", &id);
	        scanf("%d", &size[id]);
	        scanf("%d", &m); f[id].resize(m);
	        rep(j, m) {
	            scanf("%d", &f[id][j]);
	            cnt[f[id][j]][id] = true;
	            cnt[id][f[id][j]] = true;
	        }
	    }
	    printf("Case %d:\n", ++caseNo);
	    rep(i, team) {
	        puts(name[i]);
	        id = lead[i];
	        //printf("team %d: %d\n",i, id);
	        map<int, int> shirt;
	        shirt[size[id]]++;
	        rep(j, f[id].size()) {
	            int counter = 2;
	            rep(k, f[id].size())
	                counter += cnt[f[id][j]][f[id][k]];
                //printf("       %d: %d\n", f[id][j], counter);
	            if (counter >= n / team) {
                    shirt[size[f[id][j]]]++;
	            }
	        }
	        //puts("");
	        foreach(it, shirt) printf("%d %d\n", it->ff, it->ss);
	    }
	}
	return 0;
}
