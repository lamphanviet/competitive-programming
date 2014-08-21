#include <stdio.h>
#include <math.h>

int read(unsigned long *n)
{
    scanf("%ld",n);
    if (*n==0) return 1;
    else return 0;
}

int main()
{
      unsigned long n,k;
      int isEnd = read(&n);
      
      while (!isEnd)
      {
           k=(int)sqrt(n);
           if (k*k==n) printf("yes\n");
           else printf("no\n");
           isEnd = read(&n);
      }
}
