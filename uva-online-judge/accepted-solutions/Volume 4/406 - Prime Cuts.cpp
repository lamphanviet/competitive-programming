// 406 - Prime Cuts
#include <iostream>
#define N 1000

using namespace std;

int prime[N+1], np=0, pos[N+1];
bool isP[N+1];

void Sieve() {
    memset(isP, true, N+1);
    prime[np++] = 1; isP[0] = false;
    for (int i=2; i<=N; i++)
        if (isP[i]) {
            prime[np++] = i;
            for (int j=i+i; j<=N; j+=i)
                isP[j] = false;
        }
    pos[0] = -1;
    for (int i=1; i<=N; i++)
        if (isP[i]) pos[i] = pos[i-1]+1;
        else pos[i] = pos[i-1];
}

main() {
    Sieve();
    int n, m;
    while (cin >> n >> m) {
        printf("%d %d:", n, m);
        int s, f;
        if (m*2>pos[n]+1) {
            s = 0; f = pos[n];
        }
        else if (pos[n]%2) {
            s = (pos[n]+1-2*m)/2;
            f = s+2*m-1;
        }
        else {
            s = pos[n]/2-m+1;
            f = s+2*m-2;
        }
        for (; s<=f; s++)
            printf(" %d", prime[s]);
        printf("\n\n");
    }
}
