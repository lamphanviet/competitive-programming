// 11900 - Boiled Eggs
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

#define maxN 30+5
int w[maxN], n, P, Q, W;

main() {
    int kase, ans, W;
    scanf("%d", &kase);
    for (int kk=1; kk<=kase; kk++) {
        scanf("%d %d %d", &n, &P, &Q);
        for (int i=1; i<=n; i++) scanf("%d", &w[i]);
        ans = 0; W = 0;
        for (int i=1; i<=P && i<=n; i++) {
            W += w[i];
            if (W>Q) break;
            ans++;
        }
        printf("Case %d: %d\n", kk, ans);
    }
}
