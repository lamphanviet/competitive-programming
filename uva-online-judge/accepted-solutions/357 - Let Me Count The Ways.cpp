// 357 - Let Me Count The Ways
#include <iostream>

using namespace std;

#define MAXN 30000

const int coin[] = { 0, 1, 5, 10, 25, 50 };
const int M = 5;

long long ans[MAXN+5];

void DP() {
    int i, j;
    for (i=1; i<=MAXN; i++)
        ans[i] = 0;
    ans[0] = 1;
    
    for (i=1; i<=M; i++)
        for (j=0; j<=MAXN; j++)
            if (j>=coin[i]) ans[j] = ans[j] + ans[j-coin[i]];
}

main() {
    int n;
    DP();
    while (cin >> n) {
        if (ans[n]==1) printf("There is only 1 way");
        else printf("There are %lld ways", ans[n]);
        printf(" to produce %d cents change.\n", n);
    }
}
