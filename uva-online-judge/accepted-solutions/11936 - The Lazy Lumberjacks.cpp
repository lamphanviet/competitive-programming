//----------------------------
// LAM PHAN VIET
// UVA 11936 - The Lazy Lumberjacks
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

main() {
    int Case, a[4];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        sort(a, a+3);
        if (a[0]+a[1]<=a[2]) printf("Wrong!!");
        else printf("OK");
        printf("\n");
    }
}
