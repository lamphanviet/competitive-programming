// 10699 - Count the factors
#include <iostream>
#include <math.h>

using namespace std;

#define MAX 1000000

bool isprime[MAX+5];
int prime[MAX], num;

void PreCal() {
    memset(isprime, true, MAX+2);
    isprime[0] = isprime[1] = false;
    int i, j;
    for (i=2; i<=MAX; i++)
        if (isprime[i])
            for (j=i+i; j<=MAX; j+=i)
                isprime[j] = false;
    
    for (i=2, num=0; i<=MAX; i++)
        if (isprime[i])
            prime[num++] = i;
}

int CountPrime(int n) {
    if (isprime[n]) return 1;
    int i, dem = 0;
    for (i=0; prime[i]<=n; i++)
        if (n%prime[i]==0) dem++;
    return dem;
}

main() {
    PreCal();
    int n;
    while (cin >> n && n) {
        printf("%d : %d\n", n, CountPrime(n));
    }
}
