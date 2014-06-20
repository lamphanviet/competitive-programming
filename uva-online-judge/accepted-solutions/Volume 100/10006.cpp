#include <stdio.h>
#include <math.h>

int Ngto(unsigned int n)
{
    int j=1;
    unsigned int i;
    for (i=2;i<=(long)sqrt(n);i++)
        if (n%i==0)
        {
           j=0;
           break;
        }
    return j;
}

unsigned int Check(unsigned int n, unsigned int k,unsigned int i)
{
    unsigned long a=i;
    unsigned int luythua=1,x,j;
    while (luythua<=k)
    {
          luythua++;
          a=a*i;
          if (a>n) break;
    } 
    if (luythua>k)
    {
       luythua--;
       a/=i;
    }
    a=a%n;
    x=k/luythua;
    if (x!=1)
       a=Check(n,x,a);
    for (j=luythua*x+1;j<=k;j++)
        a=(a*i)%n;
    return (a);
}

int main()
{
      unsigned int i,n;
      int k;
      scanf("%d",&n);
      while (n!=0)
      {
            k=1;
            if (Ngto(n) || n%2==0) k=0;
            else
            {
                for (i=2;i<n;i++)
                    if (Check(n,n,i)!=i)
                    {
                        k=0;
                        break;
                    }
            }
            if (k) printf("The number %d is a Carmichael number.\n",n);
            else printf("%d is normal.\n",n);

            scanf("%d",&n);
      }
}
