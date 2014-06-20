//----------------------------
// LAM PHAN VIET
// UVA 10082 - WERTYU
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 1005
#define Key "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"

main() {
    int m = strlen(Key);
    char s[maxN];
    while (gets(s)) {
        int n = strlen(s);
        for (int i=0; i<n; i++)
            if (s[i]==' ') printf(" ");
            else {
                for (int j=0; j<m; j++)
                    if (s[i]==Key[j]) {
                        printf("%c", Key[j-1]);
                        break;
                    }
            }
        cout << endl;
    }
}
