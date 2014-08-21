#include <stdio.h>

#define Out 1073741824
#define SIZ 5610

struct Turtle
{
       int m,str;
} tur[SIZ];

int table[SIZ][SIZ],xm[SIZ];
int n=1;

int Min(int a, int b)
{
     if (a<b) return a;
     return b;
}

void Sapxep()
{
     Turtle temp;
     for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
             if (tur[i].str>tur[j].str || (tur[i].str==tur[j].str && tur[i].m>tur[j].m))
             {
                temp=tur[i];
                tur[i]=tur[j];
                tur[j]=temp;
             }
}

int QH()
{
    int i,j,max=1;
    xm[1]=table[1][1]=tur[1].m;
    for (i=2;i<=n;i++)
    {
        table[i][1]=tur[i].m;
        xm[i]=Min(tur[i-1].m,xm[i-1]);
    }
    
    for (j=2;j<=n;j++)
    {
        xm[j-1]=Out;
        for (i=j;i<=n;i++)
        {
            if (tur[i].m!=Out && tur[i].m+xm[i]<=tur[i].str)
               table[i][j]=tur[i].m+xm[i];
            else 
            {
                table[i][j]=Out;
                tur[i].m=Out;
            }
            if (table[i][j]<Out && j>max) max=j;
        }
        xm[j]=Out;
        for (i=j+1;i<=n;i++)
            xm[i]=Min(xm[i-1],table[i-1][j]);
    }
    return max;
}

main()
{
      int max=0;
      while (scanf(" %d %d",&tur[n].m,&tur[n].str)!=EOF)
            if (tur[n].m<=tur[n].str) n++;
      n--;
      Sapxep();
      if (n!=0) max=QH();
      printf("%d\n",max);
}
