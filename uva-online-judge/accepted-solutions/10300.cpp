// Problem 10300 - Ecological Premium
#include <iostream>

using namespace std;

main() {
    int kase, n, x, y, z, sum;
    cin >> kase;
    while (kase--) {
        cin >> n;
        sum = 0;
        while (n--) {
            cin >> x >> y >> z;
            sum += x*z;
        }
        cout << sum << endl;
    }
}
