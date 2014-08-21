#include <iostream>

using namespace std;

int Count(int n) {
    int count = n;
    while (n>=3) {
        count += n/3;
        n = n%3+n/3;
    }
    if (n==2) count++;
    return count;
}

main() {
    int n;
    while (cin >> n)
        cout << Count(n) << endl;
}
