#include <stdio.h>

main()
{
      int time, xtime, n, k, num, x, y;
      scanf("%d",&xtime);
      for (time=1;time<=xtime;time++)
      {
          scanf("%d %d %d",&x,&y,&k);
          n=x+y; num=0;
          while (n>=k)
          {
                num+= n/k;
                n = n/k + n%k;
          }
          printf("%d\n",num);
      }
}
