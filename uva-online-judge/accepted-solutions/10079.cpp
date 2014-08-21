// Problem 10079 - Pizza Cutting
#include <iostream>

using namespace std;

main() {
    long long n;
    while (cin >> n && n>=0) {
        n = (n*n+n)/2+1;
        cout << n << endl;
    }
}
