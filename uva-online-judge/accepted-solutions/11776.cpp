#include <stdio.h>

struct Plp
{
       unsigned long st,end;
} pl[1010];

int n;

void Sapxep()
{
     for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
             if (pl[i].st>pl[j].st || (pl[i].st==pl[j].st && pl[i].end>pl[j].end))
             {
                Plp temp=pl[i];
                pl[i]=pl[j];
                pl[j]=temp;
             }
}
int Run()
{
    int max=0,count,i,j;
    for (int i=1;i<=n;i++)
    {
        count=0;
        for (j=1;j<=n;j++)
        {
            if (pl[i].st<pl[j].st) break;
            if (pl[i].st<=pl[j].end)   count++;
        }
        if (count>max) max=count;
        count=0;
        for (j=1;j<=n;j++)
        {
            if (pl[i].end<pl[j].st) break;
            if (pl[i].end<=pl[j].end) count++;
        }
        if (count>max) max=count;
    }
    return max;
}

main()
{
      int i,t=0;
      scanf("%d",&n);
      while (n!=-1)
      {
            t++;
            for (i=1;i<=n;i++)
                scanf("%ld %ld",&pl[i].st,&pl[i].end);
            Sapxep();
            printf("Case %d: %ld\n",t,Run());
            scanf("%d",&n);
      }
}
