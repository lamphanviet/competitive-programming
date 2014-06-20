#include <stdio.h>
#include <string.h>

#define Key "BUSPFTM"
int n,Val['U'+1],T['U'+1];
char a[500];

void SetVal()
{
    Val[Key[0]]=1;
    for (int i=1;i<7;i++)
        Val[Key[i]]=Val[Key[i-1]]*10;
}

void SetT()
{
    for (int i=0;i<7;i++)
        T[Key[i]]=0;
}

int Rs()
{
    int rs=0;
    for (int i=0;i<7;i++)
        rs+=T[Key[i]]*Val[Key[i]];
    return rs;
}

int Check()
{
    int i;
    SetT(); T[a[0]]=1;
    if (n>63) return -1;
    if (Val[a[0]]>Val[a[n-1]])
    {
        for (i=1;i<n;i++)
        {
            T[a[i]]++;
            if (a[i]!=a[i-1] && (Val[a[i-1]]<Val[a[i]] || T[a[i-1]]>9)) return -1;
        }
        if (T[a[n-1]]>9) return -1;
        return Rs();
    }
    
    if (Val[a[0]]<Val[a[n-1]])
    {
        for (i=1;i<n;i++)
        {
            T[a[i]]++;
            if (a[i]!=a[i-1] && (Val[a[i-1]]>Val[a[i]] || T[a[i-1]]>9)) return -1;
        }
        if (T[a[n-1]]>9) return -1;
        return Rs();
    }
    else
    {
        if (n>9) return -1;
        for (i=1;i<n;i++)
            if (a[i]!=a[i-1]) return -1;
        return n*Val[a[0]];
    }
}


main()
{
  //  freopen("11787inp.txt","r",stdin);
    int k,time;
    SetVal();
    scanf("%d",&time); getchar();
    while (time>0)
    {
        gets(a); n=strlen(a);
        k=Check();
        if (k==-1) printf("error\n");
        else printf("%d\n",k);
        time--;
    }
  //  getchar();
}
