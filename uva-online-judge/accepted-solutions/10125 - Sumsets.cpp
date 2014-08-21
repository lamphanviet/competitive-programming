// 10125 - Sumsets
#include <iostream>

using namespace std;

struct Pair {
    int u, v;
} p[499505];

int n, a[1005], np;
bool con;

int Search(int c) {
    int u, v, mid;
    for (u=0, v=n-1; u<v; ) {
        mid = (u+v)/2;
        if (a[mid]==c) return mid;
        if (a[mid]<c) u = mid+1;
        else v = mid;
    }
    return u;
}

void Check(int a1, int b, int c, int d) {
    int u = Search(c);
    if (a[u]!=c) return;
    if (a1!=b && a1!=u && a1!=d && b!=u && b!=d && u!=d) {
        con = false;
        printf("%d\n", a[d]);
    }
}

main() {
//    freopen("125.inp", "r", stdin); freopen("125.out", "w", stdout);
    int i, j, c;
    while (cin >> n && n) {
        for (i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for (i=np=0; i<n; i++)
            for (j=i+1; j<n; j++) {
                p[np].u = i; p[np++].v = j;
            }
        
        for (i=n-1, con=true; i>=0 && con; i--)
            for (j=0; j<np && con; j++) {
                c = a[i] - a[p[j].u] - a[p[j].v];
                Check(p[j].u, p[j].v, c, i);
            }
        if (con) printf("no solution\n");
    }
}
