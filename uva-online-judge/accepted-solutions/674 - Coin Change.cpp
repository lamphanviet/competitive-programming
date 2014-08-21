// 674 - Coin Change
#include <iostream>

using namespace std;

const int coin[] = { 1, 5, 10, 25, 50 };
const int M = 5, N = 7489;
long long ans[N+5];

void DP() {
    int i, j;
    for (i=1; i<=N; i++)
        ans[i] = 0;
    ans[0] = 1;
    
    for (i=0; i<M; i++)
        for (j=0; j<=N; j++)
            if (j>=coin[i]) ans[j] += ans[j-coin[i]];
}

main() {
    DP();
    int n;
    while (cin >> n)
        cout << ans[n] << endl;
}
