#include <stdio.h>

int a[32767][5],cnt[110][110];
int n,road,D,S,T;

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

void Connect()
{
     int i,j;
     for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
             cnt[i][j]=0;
     for (i=1;i<=road;i++)
         cnt[a[i][1]][a[i][2]]=cnt[a[i][2]][a[i][1]]=a[i][3];
}

void QH(int tp, int plp, int from)
{
     for (int i=1;i<=n;i++)
     {
         if (cnt[tp][i]!=0 && i!=D && i!=from)
         {
            if (min(cnt[tp][i],plp) > cnt[i][D])
            {
               cnt[i][D]=min(cnt[tp][i],plp);
               if (i!=S) QH(i,cnt[i][D],tp);
            }
         }
     }
}

void KQ(int count)
{
     int result;
     if (T%(cnt[S][D]-1)!=0) result = T/(cnt[S][D]-1) + 1;
     else result = T/(cnt[S][D]-1);
     
     printf("Scenario #%d\n",count);
     printf("Minimum Number of Trips = %d\n\n",result);
}

int main()
{
      int i,j,count=0;
      scanf("%d %d",&n,&road);
      while (n!=0 && road!=0)
      {
            for (i=1;i<=road;i++)
                for (j=1;j<=3;j++)
                    scanf("%d",&a[i][j]);
            scanf("%d %d %d",&S,&D,&T);
            if (S!=D)
            {
               Connect();
               for (j=1;j<=n;j++)
                   if (cnt[D][j]!=0 && j!=D)
                      QH(j,cnt[j][D],D);
               count++;
               KQ(count);
            }
            else
            {
                count++;
                printf("Scenario #%d\n",count);
                printf("Minimum Number of Trips = 1\n\n");
            }
            
            scanf("%d %d",&n,&road);
      }
      return 0;
}
