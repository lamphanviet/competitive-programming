// 10680 - LCM
#include <iostream>
#include <math.h>

using namespace std;

#define MAXN 1000000

int luythua[MAXN+5];

bool isNgto[MAXN+5];
int ans[MAXN+5];

void PreCal() {
    int i, j, k;
    
    memset(isNgto, true, MAXN+2);
    luythua[0] = luythua[1] = -1;
    isNgto[0] = isNgto[1] = false;
    for (i=2; i<=MAXN; i++) {
        luythua[i] = -1;
        if (isNgto[i]) {
            for (j=i+i; j<=MAXN; j+=i)
                isNgto[j] = false;
        }
    }
    
    for (i=2; i<=1000; i++) {
        if (isNgto[i]) {
            for (j=i*i ; j<=MAXN; j*=i) {
                luythua[j] = i;
     //           printf("%d: %d\n", j, i);
            }
        }
    }
    
    int last = 1, temp;
    ans[0] = 1;
    for (i=1; i<=MAXN; i++) {
        temp = last;
        if (isNgto[i]) temp *= i;
        else if (luythua[i]>0)
            temp *= luythua[i];
        while (temp%10==0) temp/=10;
        ans[i] = temp%10;
        last = temp%100;
 //       cout << last << endl;
    }
}

main() {
    PreCal();
    int n;
    while (cin >> n && n)
        cout << ans[n] << endl;
}
