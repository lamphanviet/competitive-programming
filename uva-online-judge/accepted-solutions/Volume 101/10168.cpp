#include <stdio.h>
#include <math.h>

int Ngto(unsigned long k)
{
    int j=1;
    unsigned long i;
    for (i=2;i<=sqrt(k);i++)
        if (k%i==0) {
           j=0;
           break;
        }
    return j;
}

void Find(unsigned long n)
{
     unsigned long i;
     if (n%2==0 && Ngto(n-2)) printf("2 %d\n",n-2);
     else
         for (i=3;i<=n;i+=2)
             if (Ngto(i) && Ngto(n-i))
             {
                printf("%d %d\n",i,n-i);
                break;
             }
}

int main()
{
    unsigned long n;
    
    while (scanf("%d",&n)==1)
    {
          if (n<8) printf("Impossible.\n");
          else if (n%2==1)
          {
               printf("2 3 ");
               Find(n-5);
          }
          else
          {
              printf("2 2 ");
              Find(n-4);
          }
    }
    return 0;
}
