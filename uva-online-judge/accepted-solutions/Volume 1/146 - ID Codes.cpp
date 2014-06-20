// 146 - ID Codes
#include <iostream>

using namespace std;

main() {
    char str[55];
    int n, i, k;
    while (gets(str)) {
        n = strlen(str);
        if (n==1 && str[0]=='#') break;
        bool f = false;
        for (i=n-1;i>=0;i--) {
            k = i-1;
            while (k>=0 && str[k]>=str[i]) k--;
            if (k>=0) {
                f = true; break;
            }
        }
        if (f) {
            char temp = str[i]; str[i] = str[k]; str[k] = temp;
            sort(str+k+1,str+n);
            puts(str);
        }
        else cout << "No Successor" << endl;
    }
}

/*
#include <iostream>

using namespace std;

main() {
    char str[55];
    while (gets(str) && str[0]!='#') {
        if (next_permutation(str,str+strlen(str)))
            puts(str);
        else cout << "No Successor" << endl;
    }
}
*/
