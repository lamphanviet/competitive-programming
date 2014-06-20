// UVA Problem 10018 - Reverse and Add
// Accepted
#include <iostream>

using namespace std;

int a[1000];
int len,dem;

int Check() {
    for (int i=1;i<=len/2;i++)
        if (a[i]!=a[len-i+1]) return 0;
    return 1;
}

void Go() {
    dem = 0;
    int i;
    int k=5;
    while (!Check()) {
        dem++;
        for (i=1;i<=len/2;i++) {
            a[i] = a[len-i+1] = a[i]+a[len-i+1];
        }
        if (len%2) a[len/2+1] *= 2;
        int du = 0;
        for (i=1;i<=len;i++) {
            a[i] += du;
            du = a[i]/10;
            a[i] %= 10;
        }
        if (du>0) a[++len] = du;
    }
}

main() {
    int kase,n;
    cin >> kase;
    while (kase--) {
        cin >> n;
        len = 0;
        while (n!=0) {
            a[++len] = n%10;
            n/=10;
        }
        Go();
        cout << dem << " ";
        for (int i=1;i<=len;i++)
            cout << a[i];
        cout << endl;
    }
}
