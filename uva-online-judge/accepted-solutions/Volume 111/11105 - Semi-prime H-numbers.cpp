// 11105 - Semi-prime H-numbers
#include <iostream>

using namespace std;

#define MAXN 250000
#define MAX 1000005

int ans[MAXN];
bool isPrime[MAXN], isSemi[MAXN];

void PreCal() {
    int i, k;
    memset(isPrime,true,MAXN);
    memset(isSemi,false,MAXN);
    
    isPrime[0] = isPrime[0] = false;
    
    for (i=5;i<=MAX;i+=4)
        if (isPrime[i/4]) {
            for (k=i;(long long)i*(long long)k<=MAX;k+=4)
                isPrime[(i*k)/4] = false;
        }
    
    for (i=5;i<=MAX;i+=4)
        if (isPrime[i/4] && !isSemi[i/4]) {
            for (k=i;(long long)i*(long long)k<=MAX;k+=4)
                if (isPrime[k/4] && !isSemi[(i*k)/4])
                    isSemi[(i*k)/4] = true;
        }
//    for (i=0;i<=MAXN;i++)
//        if (isSemi[i])
//            printf("%d,",i*4+1);
    ans[0] = 0; int temp = 0;
    for (i=1;i<=MAXN;i++) {
        ans[i] = ans[i-1];
        if (isSemi[i]) ans[i]++;
    }
}

main() {
//    freopen("105.out","w",stdout);
    PreCal();
    int n;
    while (cin >> n && n) {
        cout << n << " " << ans[n/4] << endl;
    }
}
