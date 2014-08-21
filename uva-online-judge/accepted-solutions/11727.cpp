#include <stdio.h>

main()
{
      int time,a,c,b,i;
      scanf("%d",&time);
      for (i=1;i<=time;i++)
      {
            scanf("%d %d %d",&a,&b,&c);
            if ((a>=b && a<=c)||(a>=c && a<=b)) printf("Case %d: %d\n",i,a);
            else if ((b>=a && b<=c) || (b>=c && b<=a)) printf("Case %d: %d\n",i,b);
            else printf("Case %d: %d\n",i,c);
      }
}
