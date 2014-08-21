// 11192 - Group Reverse
#include <iostream>

using namespace std;

int n, len;
char str[110];

void Reverse(int a, int b) {
    int i, mid = (a+b)/2;
    char temp;
    for (i=a;i<=mid;i++) {
        temp = str[i]; str[i] = str[a+b-i]; str[a+b-i] = temp;
    }
}

main() {
//    freopen("192.inp","r",stdin);
//    freopen("192.out","w",stdout);
    while (scanf("%d",&n) && n) {
        scanf(" %s",&str);
        len = strlen(str);
        n = len/n;
        for (int k=0;k<len;k+=n)
            Reverse(k,k+n-1);
            
        puts(str);
    }
}
