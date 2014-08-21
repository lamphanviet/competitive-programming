// 11636 - Hello World!
#include <iostream>

using namespace std;

main() {
    int lt2[16], n , i, kase = 0;
    lt2[0] = 1;
    for (i=1;i<=14;i++)
        lt2[i] = lt2[i-1]*2;
    while (cin >> n && n>0) {
        i = 0;
        while (n>lt2[i]) i++;
        printf("Case %d: %d\n",++kase,i);
    }
}
