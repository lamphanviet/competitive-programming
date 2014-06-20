// 441 - Lotto
#include <iostream>

using namespace std;

int a[15], ans[10], n;

void Print() {
    printf("%d", ans[1]);
    for (int i=2; i<=6; i++)
        printf(" %d", ans[i]);
    cout << endl;
}

void Barrack(int i, int k) {
    if (k>6) Print();
    else {
        for (int j=i; j+6-k<n; j++) {
            ans[k] = a[j];
            Barrack(j+1, k+1);
        }
    }
}

main() {
    bool End = false;
    while (cin >> n && n) {
        if (End) cout << endl;
        End = true;
        for (int i=0; i<n; i++) cin >> a[i];
        Barrack(0, 1);
    }
}
