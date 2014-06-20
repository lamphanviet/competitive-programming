// Problem 490 - Rotating Sentences
#include <iostream>
#include <string.h>

using namespace std;

main() {
//    freopen("490.inp","r",stdin);
//    freopen("490.out","w",stdout);
    int len[110],n,max;
    char s[110][110];
    
    n = max = 0;
    while (gets(s[++n])) {
        len[n] = strlen(s[n]);
        if (len[n]>max) max = len[n];
    }
    n--;
    
    int i,j;
    for (j=0;j<max;j++) {
        for (i=n;i>=1;i--)
            if (j<len[i]) cout << s[i][j];
            else cout << " ";
        cout << endl;
    }
}
