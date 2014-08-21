// 11877 The Coco-Cola Store
#include <iostream>

using namespace std;

main() {
    int n;
    while (cin >> n && n) {
        int dem = 0;
        while (n>=3) {
            dem += n/3;
            int nn = n;
            n = nn/3 + nn%3;
        }
        if (n==2) dem++;
        cout << dem << endl;
    }
}
