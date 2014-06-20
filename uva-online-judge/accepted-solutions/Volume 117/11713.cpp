#include <stdio.h>
#include <string.h>

#define Vw "aoeui"

main()
{
      int nx,ny,i,j,kx,ky,time;
      char x[30],y[30];
      scanf("%d",&time); getchar();
      while (time>0)
      {
            gets(x); gets(y);
            nx=strlen(x); ny=strlen(y);
            if (nx!=ny) printf("No\n");
            else
            {
                for (i=0;i<nx;i++)
                    if (x[i]!=y[i])
                    {
                       kx=0; ky=0;
                       for (j=0;j<5;j++)
                           if (x[i]==Vw[j])
                           {
                              kx=1;
                              break;
                           }
                       for (j=0;j<5;j++)
                           if (y[i]==Vw[j])
                           {
                              ky=1;
                              break;
                           }
                    if (kx && ky) continue;
                    else break;
                    }
                if (i==nx) printf("Yes\n");
                else printf("No\n");                    
            }
            time--;
      }
}
