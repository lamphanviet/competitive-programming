#include <stdio.h>

int UCLN(int m, int n)
{
    if (m%n==0) return n;
    else return UCLN(n,m%n);
}

main()
{
      int a,b,result,uc;
      int time,i;
      scanf("%d",&time);
      for (i=1;i<=time;i++)
      {
          scanf("%d %d",&a,&b);
          if (a==b) result=2;
          else if (a==0 || b==0) result=1;
          else
          {
              uc=UCLN(a,b);
              result = a/uc + b/uc;
          }
          printf("Case %d: %d\n",i,result);
      }
}
          
          
