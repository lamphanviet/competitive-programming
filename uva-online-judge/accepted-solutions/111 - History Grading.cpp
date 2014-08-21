// 111 - History Grading
#include <iostream>

using namespace std;

main() {
//    freopen("111.inp","r",stdin);
//    freopen("111.out","w",stdout);
    int a[25], b[25], len[25];
    int i, j, k, n, maxlen, maxtemp;
    
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> k; a[k] = i;
    }
    
    while (cin >> k) {
        b[k] = 1; len[1] = 0;
        for (i=2;i<=n;i++) {
            cin >> k; b[k] = i;
            len[i] = 0;
        }
        
        for (i=1;i<=n;i++) {
            maxtemp = 0;
            for (j=1;j<=n;j++)
                if (a[i]==b[j]) {
                    if (len[j]<=maxtemp) len[j] = maxtemp+1;
                    else maxtemp = len[j];
                }
                else if (len[j]>maxtemp) maxtemp = len[j];
        }
        
        maxlen = len[1];
        for (i=2;i<=n;i++)
            if (len[i]>maxlen) maxlen = len[i];
        
        cout << maxlen << endl;
    }
}
