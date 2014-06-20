//----------------------------
// LAM PHAN VIET
// UVA 11752 - The Super Powers
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define lmt 65535
typedef unsigned long long ULL;
const ULL np = 5, prime[] = {2, 3, 5, 7, 11};
vector<ULL> result;

main() {
//    freopen("752.out", "w", stdout);
    result.push_back(1);
    for (ULL i=2; i<=lmt; i++) {
        double lm = (double)64.0/(double)log2((double)i);
        for (int j=0; j<np; j++) {
            ULL k = prime[j]+prime[j];
            if (k>=lm) break;
            ULL last=1, hs;
            for (int t=0; t<prime[j]; t++) last *= i;
            hs = last;
            do {
                last *= hs;
                result.push_back(last);
                k += prime[j];
            } while (k<lm);
        }
    }
    sort(result.begin(), result.end());
    
    cout << 1 << endl;
    for (ULL i=1, size=result.size(); i<size; i++)
        if (result[i]!=result[i-1])
            cout << result[i] << endl;
}
