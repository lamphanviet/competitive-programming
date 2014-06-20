// 11137 - Ingenuous Cubrency
#include <iostream>

using namespace std;

const int N = 10000, M = 21;
int coin[25];
long long ans[N+5];

void DP() {
    int i, j;
    for (i=1;i<=21;i++)
        coin[i] = i*i*i;
    
    for (i=1; i<=N; i++) ans[i] = 0;
    ans[0] = 1;
    
    for (i=1; i<=M; i++)
        for (j=0; j<=N; j++)
            if (j>=coin[i]) ans[j] += ans[j-coin[i]];
}

main() {
    DP();
    int n;
    while (cin >> n) cout << ans[n] << endl;
}
