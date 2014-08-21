// 10789 - Prime Frequency
#include <iostream>

#define N 2000

using namespace std;

bool isprime[N+5];

void Sieve() {
    memset(isprime, true, N+3);
    isprime[0] = isprime[1] = false;
    for (int i=2; i<=N; i++)
        if (isprime[i])
            for (int j=i+i; j<=N; j+=i)
                isprime[j] = false;
}

main() {
    Sieve();
    int kase, i, len, n;
    char str[N+5];
    cin >> kase; cin.get();
    for (int k=1; k<=kase; k++) {
        gets(str);
        printf("Case %d: ",k);
        bool yes = false;
        n = strlen(str);
        sort(str, str+n);
        len = 1;
        str[n] = '0';
        for (i=1; i<=n; i++)
            if (str[i]!=str[i-1]) {
                if (isprime[len]) {
                    printf("%c",str[i-1]);
                    yes = true;
                }
                len = 1;
            }
            else len++;
            
        if (!yes) printf("empty");
        cout << endl;
    }
}
