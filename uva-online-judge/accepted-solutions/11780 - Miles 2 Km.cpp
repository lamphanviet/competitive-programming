//----------------------------
// LAM PHAN VIET
// UVA 11780 - Miles 2 Km
// Time limit: 1s
//----------------------------
#include <stdio.h>
#include <math.h>

main()
{
      float k;
      int n,i;      
      scanf("%d",&n);
      while (n!=0)
      {
            k=fabs((int)(n*1.6)-(n*1.6));
            if (k==0) printf("0.00\n");
            else if (k>=0.5) printf("%.2f\n",1-k);
            else printf("%.2f\n",k);
            scanf("%d",&n);
      }
}
