/*****************/
/* LAM PHAN VIET */
/* UVA 344 - Roman Digititis
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
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
#define maxN 101
using namespace std;

struct Numbers {
    int i, v, x, l, c;
};
Numbers numbers[maxN];

void precal() {
    numbers[1].i = 1;
    numbers[1].v = numbers[1].x = numbers[1].l = numbers[1].c = 0;
    for (int i = 2; i <= 99; i++) {
        numbers[i] = numbers[i-1];
        int n = i, pos = 0, digit;
        digit = n % 10; n /= 10;
        if (digit == 4) {
            numbers[i].i++;
            numbers[i].v++;
        }
        else if (digit == 9) {
            numbers[i].i++;
            numbers[i].x++;
        }
        else {
            numbers[i].i += digit % 5;
            numbers[i].v += digit / 5;
        }
        if (!n) continue;
        digit = n % 10; n /= 10;
        if (digit == 4) {
            numbers[i].x++;
            numbers[i].l++;
        }
        else if (digit == 9) {
            numbers[i].x++;
            numbers[i].c++;
        }
        else {
            numbers[i].x += digit % 5;
            numbers[i].l += digit / 5;
        }
    }
    numbers[100] = numbers[99];
    numbers[100].c++;
}

main() {
//    FileIn("test"); FileOut("test");
    int n;
    precal();
    while (scanf("%d", &n) && n)
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, numbers[n].i, numbers[n].v, numbers[n].x, numbers[n].l, numbers[n].c);
}

/* lamphanviet@gmail.com - 2011 */
