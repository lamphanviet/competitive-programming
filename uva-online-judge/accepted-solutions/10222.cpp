#include <iostream.h>
#include <string.h>

#define Key "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"

main() {
    char str[1000];
    int n,i,k;
    gets(str);
    n=strlen(str);
    
    for (i=0;i<n;i++)
        if (str[i]!=' ') {
            k=0; str[i]=tolower(str[i]);
            while (str[i]!=Key[k]) k++;
            cout <<Key[k-2];
        }
        else cout <<" ";
    cout <<endl;
}
