//----------------------------
// LAM PHAN VIET
// UVA 11455 - Behold my quadrangle
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 4
int a[N];

int Check() {
    sort(a, a+N);
    if (a[0]==a[1] && a[2]==a[3]) {
        if (a[1]==a[2]) return 1;
        return 2;
    }
    if (a[0]+a[1]+a[2]>a[3]) return 3;
    return 4;
}

main() {
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        for (int i=0; i<N; i++)
            scanf("%d", &a[i]);
        int ans = Check();
        switch (ans) {
            case 1: printf("square"); break;
            case 2: printf("rectangle"); break;
            case 3: printf("quadrangle"); break;
            default: printf("banana");
        }
        printf("\n");
    }
}
