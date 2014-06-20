//----------------------------
// LAM PHAN VIET
// UVA 11496 - Musical Loop
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 10005
int a[maxN], n, ans;

main() {
    bool godown, goup;
    while (scanf("%d", &n) && n) {
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        godown = goup = false;
        ans = 0;
        if (a[n-1]<a[0]) goup = true;
        else godown = true;
        a[n] = a[0];
        for (int i=1; i<=n; i++)
            if (a[i-1]<a[i] && godown) {
                ans++;
                godown = false; goup = true;
            }
            else if (a[i-1]>a[i] && goup) {
                ans++;
                godown = true; goup = false;
            }
        printf("%d\n", ans);
    }
}
