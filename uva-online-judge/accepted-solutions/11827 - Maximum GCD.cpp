//*****************
// LAM PHAN VIET **
// UVA 11827 - Maximum GCD
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int GCD(int n, int m) {
    if (n%m==0) return m;
    else return GCD(m, n%m);
}

main() {
    int kase, a[105], n;
    char s[5000];
    cin >> kase;
    getchar();
    while (kase--) {
        gets(s);
        int len = strlen(s);
        int j = 0;
        n = 0;
        while (j<len) {
            while (j<len && s[j]==' ') j++;
            if (j<len) sscanf(s + j, "%d", &a[n++]);
            while (j<len && isdigit(s[j])) j++;
        }
        int rs = 0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++) {
                rs = max(GCD(a[i], a[j]), rs);
            }
        cout << rs << endl;
    }
}
