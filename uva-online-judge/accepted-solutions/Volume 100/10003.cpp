#include <stdio.h>

int len[55],cut[55],min[55][55],length[55][55];
int time,kq,max;

void Pre()
{
     time++;
     cut[0]=0; cut[time]=max;
     for (int i=1;i<=time;i++)
         len[i]=cut[i]-cut[i-1];
}

int QH()
{
     int i,j,t,temp;
     for (i=1;i<=time;i++)
     {
         min[i][i]=0;
         length[i][i]=len[i];
     }
     for (t=1;t<=time-1;t++)
     {
         for (i=1;i<=time-t;i++)
         {
             length[i][i+t]=length[i+t][i]=length[i][i+t-1]+length[i+t][i+t];
             min[i][i+t]=36720;
             for (j=i;j<=i+t;j++)
             {
                 temp=min[i][j]+min[j+1][i+t]+length[i][i+t];
                 if (temp<min[i][i+t]) min[i][i+t]=min[i+t][i]=temp;
             }
             
         }
     }
     return min[1][time];
}

main()
{
      scanf("%d",&max);
      while (max!=0)
      {
            scanf("%d",&time);
            for (int i=1;i<=time;i++)
                scanf("%d",&cut[i]);
            Pre();
            printf("The minimum cutting is %d.\n",QH());
            scanf("%d",&max);
      }
}
