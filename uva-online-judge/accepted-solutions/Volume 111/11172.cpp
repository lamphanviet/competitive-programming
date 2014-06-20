#include <iostream>

using namespace std;

main() {
    int kase, a, b;
    cin >> kase;
    while (kase--) {
        cin >> a >> b;
        if (a>b) cout << ">";
        else if (a<b) cout << "<";
        else cout << "=";
        cout << endl;
    }
}
