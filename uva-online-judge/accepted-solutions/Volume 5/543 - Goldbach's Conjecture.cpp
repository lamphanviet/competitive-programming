// 543 - Goldbach's Conjecture
#include <iostream>
#define N 1000000

using namespace std;

int prime[78500], np;
bool isP[N+5];

void Sieve() {
    memset(isP, true, N+3);
    np = 0;
    for (int i=3; i<=N; i++)
        if (isP[i]) {
            prime[np++] = i;
            for (int j=i+i; j<=N; j+=i)
                isP[j] = false;
        }
}

main() {
    Sieve();
    int n;
    while (cin >> n && n) {
        bool f = true;
        for (int nn=n/2, i=0; f && prime[i]<=nn; i++) {
            if (isP[n-prime[i]]) {
                printf("%d = %d + %d", n, prime[i], n-prime[i]);
                f = false;
            }
        }
        if (f) cout << "Goldbach's conjecture is wrong.";
        cout << endl;
    }
}
