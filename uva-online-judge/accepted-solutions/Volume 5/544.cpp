#include <stdio.h>
#include <iostream>

int n,s,f,count;
int a[205][205];
char rd[205][35];

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

int Convert(char x[])
{
    int i,j,len=strlen(x);
    for (i=1;i<=count;i++)
        if (len==strlen(rd[i]))
        {
            for (j=0; j<len && (rd[i][j]==x[j]); j++);
            if (j==len) return i;
        }
        
    count++;
    strcpy(rd[count],x);
    return count;
}

void Enter(int m)
{
    char x[100],t1[50],t2[50];
    int k,i,l,c,u,v,len;
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=0;
    
    count=0;
    while (m>0)
    {
        gets(x);
        l=0,len=strlen(x);
        
        while (x[l]!=' ') l++;
        for (i=0;i<l;i++)
            t1[i]=x[i];
        t1[l]='\0';
        
        i=++l;
        while (x[l]!=' ') l++;
        for (k=0;i<l;i++,k++)
            t2[k]=x[i];
        t2[k]='\0';
        
        ++l; c=0;
        for (i=len-1,k=1;i>=l;i--,k*=10)
            c += (x[i]-48)*k;
            
        u=Convert(t1); v=Convert(t2);
        a[u][v]=a[v][u]=c;
        
        m--;
    }
    
    gets(x);
    l=0,len=strlen(x);
    while (x[l]!=' ') l++;
    for (i=0;i<l;i++)
        t1[i]=x[i];
    t1[l]='\0';
    
    i=++l; k=1;
    for (k=0;i<len;i++,k++)
        t2[k]=x[i];
    t2[k]='\0';
    s=Convert(t1);
    f=Convert(t2);
}

void F(int u, int tm)
{
     for (int i=1;i<=n;i++)
     {
         if (a[u][i]!=0 && i!=f)
         {
            if (min(a[u][i],tm) > a[i][f])
            {
               a[i][f]=a[f][i]=min(a[u][i],tm);
               if (i!=s) F(i,a[i][f]);
            }
         }
     }
}
/*
void Print()
{
    for (int i=1;i<=n;i++)
        puts(rd[i]);
    printf("\n");
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
*/
main()
{
 //   freopen("544inp.txt","r",stdin);
 //   freopen("544out.txt","w",stdout);
    int m,time=0;
    scanf("%d %d",&n,&m);
    while (n!=0 && m!=0)
    {
        getchar();
        Enter(m);
        for (int j=1;j<=n;j++)
                   if (a[f][j]!=0 && j!=f)
                      F(j,a[j][f]);
  //      Print();
        printf("Scenario #%d\n",++time);
        int rs=a[f][s];
        printf("%d tons\n\n",rs);
        scanf("%d %d",&n,&m);
    }
}
