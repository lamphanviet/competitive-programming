// 10696 - f91
#include <iostream>

using namespace std;

int F(int a) {
    if (a>=101) return a-10;
    else return F(F(a+11));
}

main() {
    int n;
    while (cin >> n && n) {
        printf("f91(%d) = %d\n", n, F(n));
    }
}
