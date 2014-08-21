// 10878 - Decode the tape
#include <iostream>

using namespace std;

int Convert(char s[]) {
    int hs = 1, ans=0;
    for (int i=9; i>=1; i--)
        if (s[i]!='.') {
            if (s[i]=='o') ans += hs;
            hs *= 2;
        }
  //  cout << ans << endl;
    return ans;
}

main() {
  //  freopen("inp.inp", "r", stdin); freopen("inp.out", "w", stdout);
    char s[15];
    gets(s);
    while (gets(s)) {
        if (s[0]=='_') break;
        printf("%c", Convert(s));
    }
}
