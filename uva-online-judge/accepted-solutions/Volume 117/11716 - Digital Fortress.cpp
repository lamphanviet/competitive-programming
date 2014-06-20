//----------------------------
// LAM PHAN VIET
// UVA 11716 - Digital Fortress
// Time limit: 1s
//----------------------------
#include <iostream>
#include <math.h>
using namespace std;

#define maxN 10005

main() {
    int kase, n, k;
    char s[maxN];
    cin >> kase;
    getchar();  // scanf(" "); // gets(s);
    while (kase--) {
        gets(s);
        n = strlen(s);
        k = (int)sqrt(n);
        if (k*k==n) {
            for (int i=0; i<k; i++)
                for (int j=0; j<k; j++)
                    cout << s[i + j*k];
        }
        else cout << "INVALID";
        cout << endl;
    }
}
