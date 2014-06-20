#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int cube[505][10],len[505][10],nguoc[505][10];
int xmax,ymax,n;
char mat[10][10];

struct From
{
       int x,y;
} from[505][10];

void khoitao()
{
     strcpy(mat[1],"back");
     strcpy(mat[2],"front");
     strcpy(mat[3],"right");
     strcpy(mat[4],"left");
     strcpy(mat[5],"bottom");
     strcpy(mat[6],"top");
}

void Quyhoach()
{
     int t,j,u,v;
     for (t=n;t>=1;t--)
         for (j=1;j<=6;j++)
         {
             len[t][j]=1;
             from[t][j].x=0;
             from[t][j].y=0;
             for (u=t+1;u<=n;u++)
                 for (v=1;v<=6;v++)
                     if (cube[t][j]==nguoc[u][v] && len[t][j]<=len[u][v])
                     {
                        len[t][j]=len[u][v]+1;
                        from[t][j].x=u;
                        from[t][j].y=v;
                     }
         }
}

void VT_max()
{
     int max=0;
     xmax=0; ymax=0;
     for (int i=1;i<=n;i++)
         for (int j=1;j<=6;j++)
             if (len[i][j]>max)
             {
                max=len[i][j];
                xmax=i; ymax=j;
             }
}

void KQ()
{
     int t;
     printf("%d\n",len[xmax][ymax]);
     while (xmax!=0 && ymax!=0)
     {
           printf("%d ",xmax); puts(mat[ymax]); t=xmax;
           xmax=from[xmax][ymax].x; ymax=from[t][ymax].y;
     } 
     printf("\n");
}
     
main()
{
      int i,j,count=0;
      khoitao();
      
      scanf("%d",&n);
      
      while (n>0)
      {
            for (i=1;i<=n;i++)
                for (j=1;j<=6;j++)
                    scanf("%d",&cube[i][j]);
            for (i=1;i<=n;i++)
                for (j=1;j<=6;j++)
                {
                    if (j%2==0) nguoc[i][j]=cube[i][j-1];
                    else nguoc[i][j]=cube[i][j+1];
                    len[i][j]=1;
                    from[i][j].x=0;
                    from[i][j].y=0;
                }
                    
            Quyhoach();
            VT_max();
            count++;
            printf("Case #%d\n",count);
            KQ();
            
            scanf("%d",&n);
      }
}
