// 11764 - Jumping Mario
#include <iostream>
using namespace std;

main() {
    int kase;
    scanf("%d", &kase);
    for (int k=1; k<=kase; k++) {
        int n, a[55];
        int h=0, l=0;
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for (int i=1; i<n; i++)
            if (a[i-1]<a[i]) h++;
            else if (a[i-1]>a[i]) l++;
            
        printf("Case %d: %d %d\n", k, h, l);
    }
}
