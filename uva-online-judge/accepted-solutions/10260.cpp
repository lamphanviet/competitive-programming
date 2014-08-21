#include <stdio.h>
#include <string.h>
#include <iostream>

short int a['Z'+5],n;
char s[22];

void Pre() {
    for (int i='A';i<='Z';i++)
        a[i]=0;
    a['B']=a['F']=a['P']=a['V']=1;
    a['C']=a['G']=a['J']=a['K']=a['Q']=a['S']=a['X']=a['Z']=2;
    a['D']=a['T']=3;
    a['L']=4;
    a['M']=a['N']=5;
    a['R']=6;
}

main() {
    Pre();
    while (scanf("%s",&s)!=EOF) {
        n=strlen(s);
        if (a[s[0]]!=0) printf("%d",a[s[0]]);
        for (int i=1;i<n;i++)
            if (a[s[i]]!=0 && a[s[i]]!=a[s[i-1]]) printf("%d",a[s[i]]);
        printf("\n");
    }
}
