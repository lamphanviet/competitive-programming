// 524 - Prime Ring Problem
#include <iostream>

using namespace std;

const bool isP[] = {0, 0, 2, 3, 0, 5, 0, 7, 0, 0, 0, 11, 0, 13, 0, 0, 0, 17, 0, 19, 0, 0, 0, 23, 0, 0, 0, 0, 0, 29, 0, 31, 0};
bool Free[20];
int n, a[20];

void Barrack(int u, int nn) {
    if (nn==n) {
        if (!isP[a[n]+a[1]]) return;
        printf("%d", a[1]);
        for (int i=2; i<=n; i++)
            printf(" %d",a[i]);
        cout << endl;
        return;
    }
    for (int i=2; i<=n; i++)
        if (Free[i] && isP[i+u]) {
            Free[i] = false;
            a[nn+1] = i;
            Barrack(i, nn+1);
            Free[i] = true;
        }
}

main() {
    int kase = 0;
    bool End = false;
    while (cin >> n) {
        if (End) cout << endl;
        End = true;
        printf("Case %d:\n",++kase);
        if (!(n%2)) {
            memset(Free, true, 20);
            Free[1] = false; a[1] = 1;
        }
        Barrack(1, 1);
        
    }
}
