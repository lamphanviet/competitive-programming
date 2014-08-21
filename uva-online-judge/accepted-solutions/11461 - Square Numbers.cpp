// 11461 - Square Numbers

#include <iostream>
#include <math.h>

using namespace std;

main() {
    int a, b;
    while (cin >> a >> b) {
        if (!a && !b) break;
        int temp = (int)sqrt(a);
        int ans = (int)sqrt(b) - temp;
        
        if (temp*temp==a) ans++;
        cout << ans << endl;
    }
}

/*
#include <iostream>

using namespace std;

#define MAXN 100000

bool isSR[MAXN+5];
int ans[MAXN+5];

void PreCal() {
    memset(isSR, false, MAXN);
    for (int i=1; i<=315; i++) {
        isSR[i*i] = true;
    }
    ans[0] = 0;
    for (int i=1; i<=MAXN; i++) {
        ans[i] = ans[i-1];
        if (isSR[i]) ans[i]++;
    }
}

main() {
    PreCal();
    int a, b;
    while (cin >> a >> b) {
        if (!a && !b) break;
        int rs = ans[b] - ans[a];
        if (isSR[a]) rs++;
        cout << rs << endl;
    }
}
*/
