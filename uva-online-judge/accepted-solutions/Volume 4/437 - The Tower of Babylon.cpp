//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 437 - The Tower of Babylon
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
#define maxN 100000

struct Block {
	int a[3];
	Block() {}
	Block(int b[]) { a[0] = b[0], a[1] = b[1], a[2] = b[2]; }
	bool operator < (const Block &b) const {
		for (int i = 0; i < 3; i++)
			if (a[i] < b.a[i]) return true;
			else if (a[i] > b.a[i]) return false;
		return true;
	}
	bool canBuild(const Block &b) {
		return (a[0] < b.a[0] && a[1] < b.a[1]);
	}
};
vector<Block> block;
vector<int> length;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int n, a[3], cases = 0;
	while (scanf("%d", &n) && n) {
		block.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[0], &a[1], &a[2]);
			sort(a, a + 3);
			do {
				block.pb(Block(a));
			} while (next_permutation(a, a + 3));
		}
		sort(all(block));
		length.resize(block.size());
		int res = 0;
		for (int i = 0; i < block.size(); i++) {
			length[i] = block[i].a[2];
			for (int j = 0; j < block.size(); j++)
				if (block[j].canBuild(block[i]))
					length[i] = max(length[i], length[j] + block[i].a[2]);
			res = max(res, length[i]);
		}
		printf("Case %d: maximum height = %d\n", ++cases, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet