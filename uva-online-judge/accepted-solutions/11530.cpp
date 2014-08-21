#include <stdio.h>
#include <string.h>

int a[150];

void Pre() {
    a['a']=a['d']=a['g']=a['j']=a['m']=a['p']=a['t']=a['w']=a[' ']=1;
    a['b']=a['e']=a['h']=a['k']=a['n']=a['q']=a['u']=a['x']=2;
    a['c']=a['f']=a['i']=a['l']=a['o']=a['r']=a['v']=a['y']=3;
    a['s']=a['z']=4;
}

main() {
    Pre();
    int rs,time,n;
    char x[110];
    scanf("%d",&time); getchar();
    for (int t=1;t<=time;t++) {
        gets(x); rs=0; n=strlen(x);
        for (int i=0;i<n;i++) rs+=a[x[i]];
        printf("Case #%d: %d\n",t,rs);
    }
}
