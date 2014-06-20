// Problem 458 - The Decoder
#include <iostream>

using namespace std;

main() {
//    freopen("458.inp","r",stdin);
//    freopen("458.out","w",stdout);
    
    char s[100];
    while (gets(s)) {
        int i, n = strlen(s);
        for (i=0;i<n;i++)
            printf("%c",s[i]-7);
        cout << endl;
    }
}
