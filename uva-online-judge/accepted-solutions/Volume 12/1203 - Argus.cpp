//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1203 - Argus
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

struct Item {
	int id, per, time;
	Item() {}
	Item(int a, int b) { id = a, per = b, time = per; }
	Item(int a, int b, int c) { id = a, per = b, time = c; }
	bool operator < (const Item &a) const {
		if (time == a.time)
			return id < a.id;
		return time < a.time;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char s[100];
	int n, id, per;
	set<Item> heap;
	while (scanf(" %s ", &s) && strcmp(s, "#")) {
		scanf(" %d %d ", &id, &per);
		heap.insert(Item(id, per));
	}
	scanf(" %d ", &n);
	while (n--) {
		Item top = *heap.begin(); heap.erase(top);
		printf("%d\n", top.id);
		heap.insert(Item(top.id, top.per, top.time + top.per));
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet