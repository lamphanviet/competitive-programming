#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[5][5];

int Ucln(int n, int m)
{   
    if (n==0 || m==0) return 0;
    n=abs(n); m=abs(m);
    if (n%m==0) return m;
    else return Ucln(m,n%m);
}

void Inp()
{
    int lm,i,j,s,k,tmp,dau,v,hs;
    char ch[100];
    for (i=1;i<=2;i++)
        for (j=1;j<=3;j++)
            a[i][j]=0;
            
    for (int t=1;t<=2;t++)
    {
        gets(ch); lm=0; s=i=0;
        while (ch[lm]!='=') lm++;
        
        while (i<lm)
        {
            tmp=0; dau=1;
            while (ch[i]!=' ') i++;
            
            if (ch[i-1]=='+')
            {
                s=++i;
                while (i<lm && ch[i]!=' ') i++;
            }
            else if (ch[i-1]=='-')
            {
                s=++i; dau*=-1;
                while (i<lm && ch[i]!=' ') i++;
            }
            
            if (ch[i-1]=='x') { v=1; k=i-2; }
            else if (ch[i-1]=='y') { v=2; k=i-2; }
            else { v=3; k=i-1; }
            
            if (ch[s]=='-') { s++; dau*=-1; }
            
            if (k==-1 || ch[k]==' ' || ch[k]=='-') tmp=1;
            else
                for (hs=1; k>=s; k--, hs*=10)
                    tmp += (ch[k]-48)*hs;
                
            a[t][v] += tmp*dau;
            
            s=++i;
        }
        
        s=i=lm+2;
        lm=strlen(ch);
        
        while (i<lm)
        {
            tmp=0; dau=-1;
            while (i<lm && ch[i]!=' ') i++;
            
            if (ch[i-1]=='+')
            {
                s=++i;
                while (i<lm && ch[i]!=' ') i++;
            }
            else if (ch[i-1]=='-')
            {
                s=++i; dau*=-1;
                while (i<lm && ch[i]!=' ') i++;
            }
            
            if (ch[i-1]=='x') { v=1; k=i-2; }
            else if (ch[i-1]=='y') { v=2; k=i-2; }
            else { v=3; k=i-1; }
            
            if (ch[s]=='-') { s++; dau*=-1; }
            
            if (k==-1 || ch[k]==' ' ||ch[k]=='-') tmp=1;
            else
                for (hs=1; k>=s; k--, hs*=10)
                tmp += (ch[k]-48)*hs;
                
            a[t][v] += tmp*dau;
            
            s=++i;
        }
        
        a[t][3]*=-1;
    }
}

void Print()
{
    for (int i=1;i<=2;i++)
    {
        for (int j=1;j<=3;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Swap()
{
    for (int j=1;j<=3;j++)
    {
        int tmp=a[1][j];
        a[1][j]=a[2][j];
        a[2][j]=tmp;
    }
}

void Solve()
{
    int j;
    if (a[1][1]!=0 && a[2][1]!=0)
    {
        for (j=2;j<=3;j++)
        {
            a[1][j]*=a[2][1];
            a[2][j]*=a[1][1];
            a[2][j]=a[1][j]-a[2][j];
        }
        a[1][1]*=a[2][1];
        a[2][1]=0;
    }
    else if (a[2][1]!=0) Swap();
    
    if (a[1][2]!=0)
    {
        if (a[2][2]!=0)
        {
            int tmp1=a[2][2];
            int tmp2=a[1][2];
            for (j=1;j<=3;j++)
            {
                a[1][j]*=tmp1;
                a[2][j]*=tmp2;
                a[1][j]=a[2][j]-a[1][j];
            }
                
        }
        else if (a[1][1]==0) Swap();
    }
//    Print();
}

int VN()
{
    printf("don't know\n");
    printf("don't know\n");
    return 0;
}

int CN(int i)
{
    int mx=Ucln(a[i][i],a[i][3]);
    if (mx==0) printf("0\n");
    else
    {
        a[i][i]/=mx; a[i][3]/=mx;
        if (a[i][i]<0)
        {
            a[i][i]*=-1;
            a[i][3]*=-1;
        }
        printf("%d",a[i][3]);
        if (a[i][i]!=1) printf("/%d",a[i][i]);
        printf("\n");
    }
    return 0;
}

int Result()
{
    if (a[1][1]!=0 && a[1][2]!=0) return VN();
    if (a[1][1]==0 && a[1][3]!=0) return VN();
    if (a[2][2]==0 && a[2][3]!=0) return VN();
    if (a[1][1]==0 && a[2][2]==0) return VN();
    
    if (a[1][1]!=0) CN(1);
    else printf("don't know\n");
    if (a[2][2]!=0) CN(2);
    else printf("don't know\n");
    return 0;
}

main()
{
 //   freopen("367inp.txt","r",stdin);
 //   freopen("367out.txt","w",stdout);
    
    int time;
    char a[2];
    scanf("%d",&time); getchar();
    while (time-->0)
    {
        Inp();
 //       Print();
        Solve();
        Result();
        if (time!=0)
        {
            gets(a);
            printf("\n");
        }
    }
}
