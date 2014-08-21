// Problem 10038 - Jolly Jumpers
#include <iostream>
// #include <stdlib.h>

using namespace std;

int a[3010],n;
bool dif[3010];

int Check() {
    int differ;
    if (n==1) return 1;
    memset(dif,true,n+5);
    for (int i=1;i<n;i++) {
        differ = abs(a[i]-a[i+1]);
        if (differ>=n || differ==0) return 0;
        else {
            if (!dif[differ]) return 0;
            else dif[differ] = false;
        }
    }
    return 1;
}

main() {
    int x;
    while (cin >> n) {
        for (int i=1;i<=n;i++) cin >> a[i];
        if (Check()) cout << "Jolly";
        else cout << "Not jolly";
        cout << endl;
    }
}
