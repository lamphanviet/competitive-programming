#include <stdio.h>
#include <math.h>

int Ngto(unsigned long n)
{
    int i,j=1;
    if (n==2) return j;
    for (i=2;i<=sqrt(n);i++)
        if (n%i==0) {
           j=0;
           break;
        }
    return j;
}

int Sum(unsigned long n)
{
    int sum=0;
    while (n>0) {
          sum += n%10;
          n /= 10;
    }
    return sum;
}

/* int Smith(unsigned long n)
{
    int sum=0,i;
    if (n==1) return 0;
    if (Ngto(n)) return Sum(n);
    if (n%2==0) {
       sum+=2;
       sum+=(Smith(n/2));
       }
    else for (i=3;i<=n;i+=2)
             if (Ngto(i) && n%i==0) {
                sum+=Sum(i);
                sum+=Sum(Smith(n/i));
                break;
             }
    return sum;
} */ //DE QUI

main()
{
      unsigned long n, k, i;
      int time, sum_n, sum_check;
      scanf("%d",&time);
      
      while (time>0)
      {
            scanf("%d",&n);
            
            while (1)
            {
                  n++;
                  if (Ngto(n)) continue;
                  sum_n=Sum(n); sum_check=0;
                  k=n;
                  while (k!=1)
                  {
                        if (Ngto(k)) {
                           sum_check += Sum(k);
                           break;
                        }
                        if (k%2==0) {
                           sum_check += 2;
                           k = k/2;
                        }
                        else for (i=3;i<=sqrt(k);i+=2)
                                 if (Ngto(i) && k%i==0) {
                                    sum_check += Sum(i);
                                    k = k/i;
                                    break;
                                 }
                  }
                  
                  if (sum_check == sum_n) {
                     printf("%d\n",n);
                     break;
                  }

            }
            time--;
      }
}
