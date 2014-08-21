//*****************
// LAM PHAN VIET **
// UVA 514 - Rails
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
int n, a[maxN];
int Station[maxN], Top;
bool InStation[maxN];

main() {
 //   freopen("514.inp", "r", stdin); freopen("514.out", "w", stdout);
    bool Line = false;
    while (scanf("%d", &n) && n) {
        while (scanf("%d", &a[1]) && a[1]) {
            Top = 0;
            InStation[1] = false;
            For (i, 2, n) {
                scanf("%d", &a[i]);
                InStation[i] = false;
            }
            bool f = true;
            int val = 1;
            For (i, 1, n) {
                if (InStation[a[i]]) {
                    if (Station[Top]!=a[i]) f = false;
                    else Top--;
                }
                else {
                    while (val<=n && val!=a[i]) {
                        Station[++Top] = val;
                        InStation[val] = true;
                        val++;
                    }
                    val++;
                }
                if (!f) break;
            }
            if (f) puts("Yes");
            else puts("No");
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
