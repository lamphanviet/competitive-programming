//----------------------------
// LAM PHAN VIET
// UVA 11601 - Avoiding Overlaps
// Time limit: 5s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 205
bool Free[maxN][maxN];

bool isOverlap(int x1, int y1, int x2, int y2) {
    for (int i=x1+1; i<=x2; i++)
        for (int j=y1+1; j<=y2; j++)
            if (!Free[i][j]) return true;
    for (int i=x1+1; i<=x2; i++)
        for (int j=y1+1; j<=y2; j++)
            Free[i][j] = false;
    return false;
}

main() {
//    freopen("601.inp", "r", stdin); freopen("601.out", "w", stdout);
    int Case, x1, x2, y1, y2;
    int n, ans;
    scanf("%d\n", &Case);
    for (int caseNo=1; caseNo<=Case; caseNo++) {
        scanf("%d\n", &n);
        for (int i=0; i<maxN; i++)
            memset(Free[i], true, maxN);
        ans = 0;
        while (n--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (!isOverlap(x1+100, y1+100, x2+100, y2+100))
                ans += (x2-x1)*(y2-y1);
        }
        printf("Case %d: %d\n", caseNo, ans);
    }
}
