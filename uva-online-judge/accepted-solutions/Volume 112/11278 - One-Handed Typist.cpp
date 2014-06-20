// 11278 - One-Handed Typist
#include <iostream>

using namespace std;

#define Qwerty "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"
#define Dvorak "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""

char Luu[100];

void Pre() {
    int i, n = strlen(Qwerty);
    for (i=0;i<n;i++) {
        Luu[ Qwerty[i] ] = Dvorak[i];
    }
}

main() {
    int i, len;
    char str[1005];
    Pre();
    while (gets(str)) {
        len = strlen(str);
        for (i=0;i<len;i++)
            printf("%c", Luu[str[i]] );
        cout << endl;
    }
}
