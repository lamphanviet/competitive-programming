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
#define maxN 55

struct Node {
	char lab;
	int lf, rg;
	Node(char a) {
		lab = a;
		lf = rg = -1;
	}
};

vector<Node> tree;
map<int, int> pos;
char pre[maxN], in[maxN];
int n;

int newNode(char lab) {
	tree.pb(Node(lab));
	return tree.size() - 1;
}

void post(int id) {
	if (tree[id].lf != -1) post(tree[id].lf);
	if (tree[id].rg != -1) post(tree[id].rg);
	printf("%c", tree[id].lab);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d %s %s ", &n, pre, in);
		pos.clear();
		tree.clear();
		rep(i, n) pos[in[i]] = i;
		newNode(pre[0]);
		fr(i, 1, n - 1) {
			int id = 0;
			while (true) {
				if (pos[pre[i]] < pos[tree[id].lab]) {
					if (tree[id].lf == -1) {
						int k = newNode(pre[i]);
						tree[id].lf = k;
						break;
					}
					else id = tree[id].lf;
				}
				else {
					if (tree[id].rg == -1) {
						int k = newNode(pre[i]);
						tree[id].rg = k;
						break;
					}
					else id = tree[id].rg;
				}
			}
		}
		post(0);
		puts("");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */