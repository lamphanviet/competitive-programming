// 583 - Prime Factors
#include <iostream>
#define MAX 46340

using namespace std;

int prime[MAX], np=0;
int ans[200], nans, g;
bool isP[MAX+1];

void Seive() {
    memset(isP, true, MAX+1);
    for (int i=2; i<=MAX; i++)
        if (isP[i]) {
            prime[np++] = i;
            for (int j=i+i; j<=MAX; j+=i)
                isP[j] = false;
        }
}

void Solve() {
    printf("%d", g);
    nans = 0;
    if (g<0) {
        ans[nans++] = -1;
        g = -g;
    }
    int k = 0;
    while (k<np && g>1 && prime[k]<g) {
        if (g%prime[k]==0) {
            ans[nans++] = prime[k];
            g /= prime[k];
        }
        else k++;
    }
    if (g>1) ans[nans++] = g;
    
    printf(" = %d", ans[0]);
    for (int i=1; i<nans; i++)
        printf(" x %d", ans[i]);
    cout << endl;
}

main() {
    Seive();
    while (scanf("%d", &g) && g) {
        Solve();
    }
}
