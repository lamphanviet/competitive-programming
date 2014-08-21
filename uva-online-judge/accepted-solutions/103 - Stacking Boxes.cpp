// 103 - Stacking Boxes
#include <iostream>

using namespace std;

struct Box {
    int d[15];
    int cs;
} a[35];

int n, m;

bool isIns(Box x, Box y) {
    for (int i=0; i<m; i++)
        if (x.d[i]>=y.d[i]) return false;
    return true;
}

bool cmp(Box x, Box y) {
    return (isIns(x, y));
}

main() {
//    freopen("103.inp", "r", stdin); freopen("103.out", "w", stdout);
    int i, j, len[35], Trace[35], u, maxlen;
    while (scanf("%d %d", &n, &m)!=EOF) {
        for (i=1; i<=n; i++) {
            for (j=0; j<m; j++)
                scanf("%d", &a[i].d[j]);
            a[i].cs = i;
            sort(a[i].d, a[i].d+m);
        }
        stable_sort(a+1, a+n+1, cmp);

        for (i=1, maxlen=0; i<=n; i++) {
            len[i] = 1; Trace[i] = 0;
            for (j=1; j<i; j++)
                if (isIns(a[j], a[i]) && len[j]+1 > len[i]) {
                    Trace[i] = j; len[i] = len[j]+1;
                }
            if (len[i]>maxlen) {
                u = i; maxlen = len[i];
            }
        }
        
        printf("%d\n", maxlen); i=0;
        while (u>0) {
            len[++i] = a[u].cs; u = Trace[u];
        }
        printf("%d",len[maxlen]);
        for (i=maxlen-1; i>=1; i--)
            printf(" %d", len[i]);
        cout << endl;
    }
}
