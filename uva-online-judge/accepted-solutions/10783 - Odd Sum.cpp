#include <stdio.h>

int main()
{
      int a,b,i,xtime,time,sum;
      scanf("%d",&xtime);
      for (time=1;time<=xtime;time++)
      {
            scanf("%d\n%d",&a,&b);
            sum=0;
            if (a%2==0) a++;
            if (b%2==0) b--;
            for (i=a;i<=b;i+=2)
                sum+=i;
            printf("Case %d: %d\n",time,sum);
      }
      return 0;
}
