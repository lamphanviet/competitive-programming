// UVA Problem 11830 - Contract Revision
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2930
#include <iostream>

using namespace std;

main() {
    int i,len,j,k,n;
    char s[110],xoa,rs[110];
    while (1) {
        scanf("%c %s",&xoa,&s);
        n = strlen(s);
        if (xoa=='0' && n==1 && s[0]=='0') break;
        k = 0;
        for (i=0;i<n;i++)
            if (s[i]!=xoa) rs[++k] = s[i];
        i = 1;
        while (rs[i]=='0' && i<=k) i++;
        if (i>k) cout << '0';
        else {
            while (i<=k) cout << rs[i++];
        }
        cout << endl;
        scanf(" ");
    }
}
