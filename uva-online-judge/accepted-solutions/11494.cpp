#include <stdio.h>
#include <stdlib.h>

short int a,b,c,d;

short int Check() {
    if (a==c && b==d) return 0;
    if (a==c || b==d) return 1;
    if (abs(a-c)==abs(b-d)) return 1;
    return 2;
}

main() {
    scanf("%d %d %d %d",&a,&b,&c,&d);
    while (a!=0 && b!=0 && c!=0 && d!=0) {
        printf("%d\n",Check());
        scanf("%d %d %d %d",&a,&b,&c,&d);
    }
}
