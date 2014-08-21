//*****************
// LAM PHAN VIET **
// UVA 12010 - Boring Homework 
// Time limit: 1.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Forv(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 90
using namespace std;

int n, Node[maxN], Left[maxN], Right[maxN];
char s[200][200];

void Insert(int i, int p) {
    if (i==p) return;
    if (Node[p]<Node[i]) {
        if (!Left[i]) Left[i] = p;
        Insert(Left[i], p);
    }
    else {
        if (!Right[i]) Right[i] = p;
        Insert(Right[i], p);
    }
}

void Process(int p, int pos, int lvl) {
    if (lvl>0) s[lvl-1][pos] = '|';
    s[lvl][pos] = 'o';
    if (Left[p]) {
        int len = Node[p] - Node[Left[p]] - 1, i = pos-1;
        while (len--) s[lvl][i--] = '-';
        s[lvl][i] = '+';
        Process(Left[p], i, lvl+2);
    }
    if (Right[p]) {
        int len = Node[Right[p]] - Node[p] - 1, i = pos+1;
        while (len--) s[lvl][i++] = '-';
        s[lvl][i] = '+';
        Process(Right[p], i, lvl+2);
    }
}

main() {
 //   FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        scanf("%d", &n);
        For (i, 1, n) Left[i] = Right[i] = 0;
        For (i, 1, n) {
            scanf("%d", &Node[i]);
            Insert(1, i);
        }
        Fill(s, ' ');
        Process(1, Node[1]-1, 0);
        printf("Case #%d:\n", kk);
        For (k, 0, 199) {
            int i = 199;
            while (i>=0 && s[k][i]==' ') i--;
            if (i<0) break;
            s[k][++i] = '\0';
            puts(s[k]);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
