// Problem 494 - Kindergarten Counting Game
#include <iostream>

using namespace std;

char s[1000];

int isWord(char k) {
    if ((s[k]>='A' && s[k]<='Z') || (s[k]>='a' && s[k]<='z')) return 1;
    return 0;
}

main() {
//    freopen("494.inp","r",stdin);
//    freopen("494.out","w",stdout);
    int n,k,count,last,now;
    while (gets(s)) {
        n = strlen(s);
        count = 0;
        last = isWord(0);
        if (last) count++;
        for (k=1;k<n;k++) {
            now = isWord(k);
            if (now && !last) count++;
            last = now;
        }
        cout << count << endl;
    }
}
