#include <stdio.h>

main()
{
      int k,n,r,time=0;
      scanf("%d %d",&r,&n);
      while (n!=0 || r!=0)
      {
            time++;
            printf("Case %d: ",time);
            for (k=0;k<=26;k++)
                if ((k+1)*n>=r) break;
            if (k>26) printf("impossible\n");
            else printf("%d\n",k);
            scanf("%d %d",&r,&n);
      }
}
