#include <stdio.h>
#include <string.h>

void Print(int a[], int b[])
{
     int i;
     for (i=0;i<31;i++)
         printf("%d",a[i]);
     printf(" ");
     for (i=0;i<31;i++)
         printf("%d",b[i]);
     printf("\n");
}

void Print_over(int a[])
{
     for (int i=0;i<31;i++)
         printf("%d",a[i]);
     printf(" ");
     printf("overflow\n");
}

void F(int a[], int b[])
{
     int i,c[35],d[35],k=0;
     Print(a,b);
     for (i=0;i<31;i++)
         if (a[i]!=b[i])
         {
            c[i]=1;
            d[i]=0;
         }
         else
         {
             c[i]=0;
             if (a[i])
             {
                d[i]=1;
                k=1;
             }
             else d[i]=0;
         }
         
     if (d[0]==1) Print_over(c);
     else if (!k) Print(c,d);
     else
     {
         for (i=0;i<30;i++)
             d[i]=d[i+1];
         d[30]=0;
         F(c,d);
     }
}

main()
{
      int time,i,j;
      int a[35],b[35];
      char temp[70];
      scanf("%d",&time); getchar();
      while (time>0)
      {
            gets(temp);
            for (i=0;i<31;i++)
                a[i]=temp[i]-48;
            for (i=32,j=0;i<64;i++,j++)
                b[j]=temp[i]-48;
            F(a,b);
            if (time!=1) printf("\n");
            time--;
      }
}
