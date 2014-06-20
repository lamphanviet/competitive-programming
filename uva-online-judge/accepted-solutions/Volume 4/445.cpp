// Problem 445 - Marvelous Mazes
#include <iostream>
#include <string.h>

using namespace std;

main() {
//    freopen("445.inp","r",stdin);
//    freopen("445.out","w",stdout);
    
    char out, s[133];
    int n,i,time;
    
    while (gets(s)) {
        n = strlen(s);
        if (n==0) {
            cout << endl;
            continue;
        }
        time = 0;
        for (i=0;i<n;i++) {
            if (s[i]=='!') cout << endl;
            else if (s[i]>='0' && s[i]<='9') time+=s[i]-48;
            else {
                out = s[i];
                if (s[i]=='b') out = ' ';
                while (time-->0) cout << out;
                time = 0;
            }
        }
        cout << endl;
    }
}
