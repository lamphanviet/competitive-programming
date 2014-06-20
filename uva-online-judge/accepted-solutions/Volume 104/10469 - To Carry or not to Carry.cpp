// 10469 - To Carry or not to Carry
#include <iostream>

using namespace std;

main() {
    long a, b;
    while (cin >> a >> b) {
        long ans = a ^ b;
        cout << ans << endl;
    }
}
