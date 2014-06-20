#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

short int gtr[105][10005][105];
bool tb[105][10005];
int nx,ny;


void Sum(int x1, int y1, int x2, int y2, int t)
{
     short int sum[102];
     sum[0]=gtr[x1][y1][0];
     int i=1,temp=0;
     while (i<=gtr[x2][y2][0])
     {
            sum[i]=(gtr[x1][y1][i]+gtr[x2][y2][i]+temp)%10;
            temp=(gtr[x1][y1][i]+gtr[x2][y2][i]+temp)/10;
            if (i==gtr[x2][y2][0])
            {
               if (temp==0)
                  for (++i;i<=sum[0];i++)
                      sum[i]=gtr[x1][y1][i];
               else
               {
                   for (++i;i<=sum[0];i++)
                   {
                       sum[i]=(gtr[x1][y1][i]+temp)%10;
                       temp=(gtr[x1][y1][i]+temp)/10;
                   }
                   if (temp>=10)
                   {
                      sum[++sum[0]]=0;
                      sum[++sum[0]]=1;
                   }
                   else if (temp>0)
                        sum[++sum[0]]=temp;
               }
            }
            i++;
      }
      if (t==1)
         for (i=0;i<=sum[0];i++)
             gtr[x1][y1][i]=sum[i];
      else
          for (i=0;i<=sum[0];i++)
             gtr[x2][y2][i]=sum[i];
}

void KQ()
{
     gtr[1][1][0]=1; gtr[1][1][1]=0;
     for (int j=nx-1;j>=0;j--)
         if (tb[0][j]) {
            if (gtr[1][1][0]>=gtr[0][j][0]) Sum(1,1,0,j,1);
            else Sum(0,j,1,1,2); }
     
     for (int i=gtr[1][1][0];i>=1;i--)
         printf("%d",gtr[1][1][i]);
     printf("\n");
}

main()
{
      int i,j,k,time,u,v;
      char x[10005],y[105];
      scanf("%d",&time); getchar();
      while (time>0)
      {
            gets(x);
            gets(y);
            nx=strlen(x); ny=strlen(y);
         if (nx==0 || ny==0) printf("0\n");
         else 
         {
            for (j=0;j<=nx-1;j++)                          //Do dong cuoi
            {
                tb[ny-1][j]=false;
                if (x[j]==y[ny-1])
                {
                   tb[ny-1][j]=true;
                   gtr[ny-1][j][0]=1;
                   gtr[ny-1][j][1]=1;
                }
            }
            
            gtr[ny][nx-1][0]=1; gtr[ny][nx-1][1]=0;
            for (i=ny-2;i>=0;i--)
            {
                u=ny; v=nx-1;
                for (j=nx-1;j>=0;j--)
                {
                    tb[i][j]=false;
                    if (x[j]==y[i])
                    {
                       gtr[i][j][0]=1; gtr[i][j][1]=0;
                       for (k=j+1;k<=v;k++)
                           if (tb[i+1][k])
                           {
                              if (gtr[i][j][0]>gtr[i+1][k][0]) Sum(i,j,i+1,k,1);
                              else Sum(i+1,k,i,j,2);
                              tb[i][j]=true;
                           }
                       if (u!=ny)
                       {
                          if (gtr[i][j][0]>gtr[u][v][0]) Sum(i,j,u,v,1);
                          else Sum(u,v,i,j,2);
                          tb[i][j]=true;
                       }
                       if (tb[i][j]) { u=i; v=j; }
                    }
                }
            }
            KQ();
    /*        for (i=0;i<=ny-1;i++)
            {
                for (j=0;j<=nx-1;j++)
                    printf("%3d",tb[i][j]);
                printf("\n");
            }                */
         }
            time--;
      }
}
