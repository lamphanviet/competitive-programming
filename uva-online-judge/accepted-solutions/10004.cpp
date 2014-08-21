#include <stdio.h>
#include <iostream>

int uncolor,socanh,sodinh;
int khoa[210],maudinh[210],a[1000][5];

void check(int dinh)
{
     int i,j,x;
     for (i=1;i<=socanh;i++)
     {
         if (uncolor) break;
         for (j=1;j<=2;j++)
         {
             if (uncolor) break;
             if (a[i][j]==dinh)
             {
                if (j==1) x=2;
                else x=1;
                if (!khoa[a[i][x]])
                {
                   maudinh[a[i][x]]=!maudinh[dinh];
                   khoa[a[i][x]]=1;
                   check(a[i][x]);
                }
                else
                {
                    if (maudinh[a[i][x]]==!maudinh[dinh]) break;
                    else
                    {
                        uncolor=1;
                        break;
                    }
                }
             }
         }
     }
}

main()
{
      int i;
      
      scanf("%d",&sodinh);
      
      while (sodinh!=0)
      {
            scanf("%d",&socanh);
            for (i=1;i<=socanh;i++)
                scanf("%d %d",&a[i][1],&a[i][2]);
                
            for (i=0;i<=205;i++) {
                khoa[i]=0;
                maudinh[i]=0;
            }
            khoa[a[1][1]]=1;
            uncolor=0;
            check(a[1][1]);
            
            if (uncolor) printf("NOT BICOLORABLE.\n");
            else printf("BICOLORABLE.\n");
            
            scanf("%d",&sodinh);
      }
}
