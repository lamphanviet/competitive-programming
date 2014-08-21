// 10611 - The Playboy Chimp
#include <iostream>
#define N 50000

using namespace std;

main() {
    int n, m, a[N+5];
    scanf("%d", &m);
    n = 0;
    if (m--) scanf("%d", &a[n++]);
    while (m--) {
        scanf("%d", &a[n]);
        if (a[n]>a[n-1]) n++;
    }
    
    int u, v ,mid, x;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &x);
        for (u=0, v=n-1; u<v; ) {
            mid = (u+v)/2;
            if (a[mid]<x) u = mid+1;
            else v = mid;
        }
        
        if (a[u]<x) printf("%d", a[u]);
        else if (u-1>=0 && a[u-1]<x) printf("%d", a[u-1]);
        else printf("X");
        
        if (a[u]>x) printf(" %d\n", a[u]);
        else if (u+1<n) printf(" %d\n", a[u+1]);
        else printf(" X\n");
    }
}
