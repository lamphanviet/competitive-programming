// 10812 - Beat the Spread!
#include <iostream>

using namespace std;

main() {
    int kase, a, b, hieu, tong;
    cin >> kase;
    while (kase--) {
        cin >> tong >> hieu;
        a = tong-hieu;
        if (a<0 || a%2)
            printf("impossible");
        else {
            a = a/2;
            b = tong-a;
            printf("%d %d", b, a);
        }
        cout << endl;
    }
}
