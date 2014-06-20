// 11547 - Automatic Answer
#include <iostream>

using namespace std;

main() {
    int kase, n;
    cin >> kase;
    while (kase--) {
        cin >> n;
        n = 315*n+36962;
        n /= 10; n%=10;
        cout << abs(n) << endl;
    }
}
