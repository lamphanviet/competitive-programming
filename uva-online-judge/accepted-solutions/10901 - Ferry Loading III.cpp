//*****************
// LAM PHAN VIET **
// UVA 10901 - Ferry Loading III
// Time limit: 
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
#define maxN 10001
class Ferry {
public:
    int pos, arvtime;
    Ferry() { pos=arvtime=0; }
    Ferry(int p, int arvt) {
        pos = p; arvtime = arvt;
    }
};
queue<Ferry> Side[2];   // side 0: left - side 1: right
int N, n, Time, ans[maxN];

void Solve() {
    int sd = 0, CurrentTime = 0, Count = 0;
    while (!Side[0].empty() || !Side[1].empty()) {
        Count = 0;
        while (!Side[sd].empty() && Count<N) {
            Ferry f = Side[sd].front();
            if (f.arvtime<=CurrentTime) {
                ans[f.pos] = CurrentTime + Time;
                Count++;
                Side[sd].pop();
            }
            else break;
        }
        if (Count==0) {
            if (Side[sd].empty()) {
                CurrentTime = max(CurrentTime, Side[1-sd].front().arvtime) + Time;
                sd = 1 - sd;
            }
            else if (Side[1-sd].empty()) {
                CurrentTime = Side[sd].front().arvtime;
            }
            else {
                int a = Side[sd].front().arvtime, b = Side[1-sd].front().arvtime;
                if (a<=b) CurrentTime = a;
                else {
                    CurrentTime = max(CurrentTime, b) + Time;
                    sd = 1 - sd;
                }
            }
            continue;
        }
        CurrentTime += Time; // cross the river
        sd = 1 - sd;    // change side
    }
}

main() {
//    freopen("901.inp", "r", stdin); freopen("901.out", "w", stdout);
    int Case, arvt;
    char bank[10];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d %d", &N, &Time, &n);
        For (i, 1, n) {
            scanf("%d %s", &arvt, &bank);
            if (!strcmp(bank, "left")) Side[0].push(Ferry(i, arvt));
            else Side[1].push(Ferry(i, arvt));
        }
        Solve();
        For (i, 1, n) printf("%d\n", ans[i]);
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
