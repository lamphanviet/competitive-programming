// 11386 - Triples
#include <iostream>

using namespace std;

int C[4][5005];

void Pre() {
    int i;
    C[2][2] = 1;
    for (i=3;i<=5000;i++)
        C[2][i] = C[2][i-1]+i-1;
}

main() {
    //freopen("386.inp","r",stdin);
    //freopen("386.out","w",stdout);
    Pre();
    int k, i, p, q, demp, demq;
    int a[5005], n;
    unsigned long long xy, z, dem;
    while (cin >> n) {
        for (i=1;i<=n;i++) cin >> a[i];
        sort(a+1, a+n+1);
        dem = 0;
        for (k=n;k>=3;k--) {
            p = 1; q = n-1;
            z = a[k];
            while (p<q) {
                xy = a[p]+a[q];
                if (xy==z) {
                    if (a[p]==a[q]) {
                        dem += C[2][q-p+1];
                        break;
                    }
                    else {
                        demp = demq = 1;
                        while (a[p]==a[p+1]) {
                            p++; demp++;
                        }
                        while (a[q]==a[q-1]) {
                            q--; demq++;
                        }
                        dem += demp*demq;
                        p++; q--;
                    }
                }
                else if (xy<z) p++;
                else q--;
            }
        }
        cout << dem << endl;
    }
}
