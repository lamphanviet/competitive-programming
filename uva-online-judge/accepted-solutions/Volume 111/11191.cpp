// Problem 11192 - Group Reverse

#include <iostream>

using namespace std;

main() {
//    freopen("92.inp","r",stdin);
//    freopen("92.out","w",stdout);
    int G,n,temp,i,j;
    char s[110];
    while (cin >> G && G!=0) {
        scanf("%s",&s);
        n = strlen(s);
        G = n/G;
        temp = G/2;
        for (i=0;i<n;i+=G) {
            for (j=0;j<=temp;j++) {
                char tempchar = s[i+j];
                s[i+j] = s[i+G-j-1];
                s[i+G-j-1] = tempchar;
            }
        }
        puts(s);
    }
}
