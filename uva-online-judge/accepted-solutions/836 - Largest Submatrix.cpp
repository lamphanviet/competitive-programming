// 836 - Largest Submatrix
#include <iostream>

using namespace std;

main() {
//    freopen("836.inp", "r", stdin); freopen("836.out", "w", stdout);
    int kase, i, j, k;
    int a[30][30], n;
    char s[30]; 
    cin >> kase; cin.get();
    for (i=0; i<30; i++) a[0][i] = 0;
    while (kase--) {
        cin.get();
        gets(s); n = strlen(s);
        i = 1;
        do {
            for (j=1; j<=n; j++)
                a[i][j] = a[i-1][j] + s[j-1]-48;
  //          gets(s);
        } while (++i<=n && gets(s));
        
        int maxsum = a[1][1];
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                int tempsum = 0;
                for (k=1; k<=n; k++) {
                    int temp = a[j][k] - a[i-1][k];
                    if (temp==j-i+1) tempsum += temp;
                    else tempsum = 0;
                    if (tempsum > maxsum) maxsum = tempsum;
                }
            }
        cout << maxsum << endl;
        if (kase) cout << endl;
    }
}
