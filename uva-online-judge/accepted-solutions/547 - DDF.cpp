/*****************/
/* LAM PHAN VIET */
/* UVA 547 - DDF
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 3001
using namespace std;

int next[maxN], length[maxN];

int sum_digit(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void precal() {
    Fill(next, 0);
    for (int i = 1; i < maxN; i++) {
        int sum = sum_digit(i);
        for (int j = i; j < maxN; j += i)
            next[j] += sum;
    }
    length[0] = 0;
    for (int i = 1; i < maxN; i++) {
        length[i] = 1;
        int j = next[i], last = i;
        while (j != last) {
            last = j;
            j = next[j];
            length[i]++;
        }
    }
}

int P[maxN * 3], Max[maxN * 3];

void build_tree(int p, int L, int R) {
    if (L == R) {
        P[p]= L;
        Max[p] = length[L];
        return;
    }
    int c = p << 1, mid = (L + R) >> 1;
    build_tree(c, L, mid);
    build_tree(c + 1, mid + 1, R);
    Max[p] = Max[c];
    P[p] = P[c];
    if (Max[c + 1] > Max[p]) {
        Max[p] = Max[c + 1];
        P[p] = P[c + 1];
    }
}

int pos_max, len_max;

void get_max_pos(int p, int L, int R, int U, int V) {
    if (V < L || R < U) return;
    if (U <= L && R <= V) {
        if (Max[p] > len_max) {
            len_max = Max[p];
            pos_max = P[p];
        }
        return;
    }
    int c = p << 1, mid = (L + R) >> 1;
    get_max_pos(c, L, mid, U, V);
    get_max_pos(c + 1, mid + 1, R, U, V);
}

main() {
//    FileIn("test"); FileOut("test");
    precal();
    build_tree(1, 0, 3000);
    int Case = 0, n, m, nn, mm;
    while (scanf("%d %d", &nn, &mm) != EOF) {
        n = min(nn, mm);
        m = max(nn, mm);
        pos_max = 0; len_max = -1;
        get_max_pos(1, 0, 3000, n, m);
        printf("Input%d: %d %d\n", ++Case, nn, mm);
        printf("Output%d:", Case);
        int last;
        do {
            printf(" %d", pos_max);
            last = pos_max;
            pos_max = next[pos_max];
        } while (pos_max != last);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
