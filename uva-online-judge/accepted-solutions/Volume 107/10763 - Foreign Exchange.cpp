// 10763 - Foreign Exchange
#include <iostream>
#define N 500005

using namespace std;

int a[N], b[N], n;

bool Check() {
    sort(a, a+n); sort(b, b+n);
    for (int i=0; i<n; i++)
        if (a[i]!=b[i]) return false;
    return true;
}

main() {
    while (cin >> n && n) {
        for (int i=0; i<n; i++) {
            scanf("%d %d", &a[i], &b[i]);
        }
        if (Check()) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
