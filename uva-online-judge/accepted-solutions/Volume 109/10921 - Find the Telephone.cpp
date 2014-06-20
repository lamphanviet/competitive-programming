// 10921 - Find the Telephone
#include <iostream>

using namespace std;

int num[125];

void Pre() {
    for (int i='A',k=6;i<='U';i++,k++) {
        num[i] = k/3;
    }
    num['S'] = 7; num['V'] = 8;
    for (int i='W';i<='Z';i++)
        num[i] = 9;
}

main() {
    char s[35];
    int i,n;
    Pre();
    while (gets(s)) {
        n = strlen(s);
        for (i=0;i<n;i++)
            if ((s[i]>='0' && s[i]<='9') ||s[i]=='-')
                cout << s[i];
            else cout << num[s[i]];
        cout << endl;
    }
}
