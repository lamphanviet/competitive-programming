// 10474 - Where is the Marble?
#include <iostream>

using namespace std;

int n, a[10005], vt[10005];

int Find(int x) {
    int u, v;
    for (u=0, v=n-1; u<v; ) {
        int mid = (u+v)/2;
        if (a[mid]<x) u = mid+1;
        else v = mid;
    }
    if (a[u]==x) return vt[u]+1;
    else return -1;
}

main() {
    int kase=0, i, x, q;
    while (scanf("%d %d", &n, &q)) {
        if (!n && !q) break;
        for (i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for (i=1, vt[0]=0; i<n; i++)
            if (a[i]==a[i-1]) vt[i] = vt[i-1];
            else vt[i] = i;
        printf("CASE# %d:\n", ++kase);
        for (i=0; i<q; i++) {
            scanf("%d", &x);
            int ans = Find(x);
            if (ans>=0) printf("%d found at %d\n", x, ans);
            else printf("%d not found\n", x);
        }
    }
}
