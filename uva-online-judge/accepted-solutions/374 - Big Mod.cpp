// 374 - Big Mod
#include <iostream>

using namespace std;

typedef unsigned long long Type;

Type n, m;

Type R(Type n, Type u) {
    if (u==1) return n%m;
    
    Type half, last;
    half = R(n,u/2);
    last = u%2;
    if (last) return ((half*half*n)%m);
    else return ((half*half)%m);
}

main() {
    Type k, ans;
    while (cin >> n >> k >> m) {
        if (n==0 || m==1) ans = 0;
        else if (k==0) ans = 1%m;
        else ans = R(n, k);
        
        cout << ans << endl;
    }
}
