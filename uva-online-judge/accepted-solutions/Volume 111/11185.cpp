#include <iostream>

using namespace std;

main() {
    int n,i,k,a[1000];
    while (cin >> n && n>=0) {
        k = -1;
        if (n==0) cout << 0;
        while (n!=0) {
            a[++k] = n%3;
            n/=3;
        }
        for (i=k;i>=0;i--)  cout << a[i];
        cout << endl;
    }
}
