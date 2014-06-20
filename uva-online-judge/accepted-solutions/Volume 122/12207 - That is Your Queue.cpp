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
#define maxN 100111

int n, q, id;
char ch;
deque<int> head, tail;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int caseNo = 0;
	while (scanf("%d %d ", &n, &q) && (q | n)) {
	    head.clear(); tail.clear();
	    printf("Case %d:\n", ++caseNo);
	    fr(i, 1, min(n, 2000)) head.pb(i);
	    while (q--) {
	        scanf(" %c ", &ch);
	        while (!head.empty() && head.front() < 0) {
	            head.pop_front();
	        }
	        while (!tail.empty() && tail.front() < 0) {
	            tail.pop_front();
	        }
	        while (head.empty()) {
	            int val = tail.front();
	            head.pb(val);
	            tail.pop_front();
	        }
	        if (ch == 'N') {
	            printf("%d\n", head.front());
	            int val = head.front();
	            tail.pb(val);
	            head.pop_front();
	        }
	        else {
	            scanf(" %d ", &id);
	            foreach (it, head) if (*it == id) {
	                *it = -1;
	                break;
	            }
	            foreach (it, tail) if (*it == id) {
	                *it = -1;
	                break;
	            }
	            head.push_front(id);
	        }
	    }
	}
	return 0;
}
