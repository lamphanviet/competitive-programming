// UVA Problem 272 - TEX Quotes
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=208
#include <iostream>
using namespace std;

main() {
    int i,n,k=0;
    char s[1000];
    while (gets(s)) {
        n = strlen(s);
        for (i=0;i<n;i++)
            if (s[i]=='"') {
                if (!k) {
                    printf("``"); k++;
                }
                else {
                    printf("''"); k--;
                }
            }
            else printf("%c",s[i]);
        cout << endl;
    }
}
