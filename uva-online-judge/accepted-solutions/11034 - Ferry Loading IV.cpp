//*****************
// LAM PHAN VIET **
// UVA 11034 - Ferry Loading IV
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
int L;
queue<int> Side[2];

void Solve() {
    int Count = 0, sd = 0;
    while (!Side[0].empty() || !Side[1].empty()) {
        int curLen = 0;
        while (!Side[sd].empty()) {
            int len = Side[sd].front();
            if (len + curLen <= L) {
                curLen += len;
                Side[sd].pop();
            }
            else break;
        }
        Count++;
        sd = 1-sd;
    }
    printf("%d\n", Count);
}

main() {
//    freopen("034.inp", "r", stdin); freopen("034.out", "w", stdout);
    int Case, len, m;
    char bank[10];
    scanf("%d", &Case);
    while (Case--) {
        Side[0] = Side[1] = queue<int>();
        scanf("%d %d", &L, &m); L *= 100;
        while (m--) {
            scanf("%d %s", &len, &bank);
  //          printf("%d %s\n", len, bank);
            if (!strcmp(bank, "left")) Side[0].push(len);
            else Side[1].push(len);
        }
        Solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
