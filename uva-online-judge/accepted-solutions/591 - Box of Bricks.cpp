// 591 - Box of Bricks
#include <iostream>

using namespace std;

main() {
    int n, a[55];
    int i, sum, avg, kase = 0;
    while (cin >> n) {
        if (n==0) break;
        avg = 0;
        for (i=0;i<n;i++) {
            cin >> a[i];
            avg += a[i];
        }
        avg /= n; sum = 0;
        for (i=0;i<n;i++)
            if (a[i]>avg) sum += a[i]-avg;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",++kase,sum);
    }
}
