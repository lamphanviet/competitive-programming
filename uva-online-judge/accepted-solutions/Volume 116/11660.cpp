#include <stdio.h>
#include <string.h>

int u,v;
char x[30];

void Swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void V(char xn[])
{
    char tmp[2][v+5];
    int a=0,b=1,count=1,i;
    for (i=0;i<strlen(xn);i++)
        tmp[0][i]=xn[i];
    tmp[0][i]='\0';
        
    while (count!=u)
    {
        count++;
        int n=strlen(tmp[a]),t=0,k=1;
        for (i=1;i<n;i++)
        {
            if (t>v+5) break;
            if (tmp[a][i]==tmp[a][i-1]) k++;
            else
            {
                tmp[b][t++]=k+48;
                tmp[b][t++]=tmp[a][i-1];
                k=1;
            }
        }
        tmp[b][t++]=k+48;
        tmp[b][t++]=tmp[a][i-1];
        tmp[b][t]='\0';
        Swap(&a,&b);
    }
    printf("%c\n",tmp[a][v-1]);
}

void Convert(char s[])
{
    int n=strlen(s),i,k;
    for (i=0;i<n;i++)
        if (s[i]==' ') break;
        else x[i]=s[i];
    x[i]='\0';
    for (i=n-1,k=1;i>=0;i--,k*=10)
        if (s[i]==' ') break;
        else v+=k*(s[i]-48);
        
    for (i--,k=1;i>=0;i--,k*=10)
        if (s[i]==' ') break;
        else u+=k*(s[i]-48);
}

main()
{
    char s[30];
    gets(s); u=v=0;
    Convert(s);
    while (x[0]!=0 && u!=0 && v!=0)
    {
        V(x); 
        gets(s); u=v=0;
        Convert(s);
    }
}
