#include <stdio.h>

unsigned long gt[15];

void Giaithua()
{
     gt[0]=1;
     for (int i=1;i<=12;i++)
         gt[i]=gt[i-1]*i;
}

void Swap(int *a, int *b)
{
     int temp;
     temp=*a;
     *a=*b;
     *b=temp;
}

int C(int n, int k)
{
    return gt[n]/(gt[n-k]*gt[k]);
}

int F(int n, int fnt)
{
    int rs=0;
    if (n==fnt) return 1;
    if (fnt==1) return gt[n-1];
    for (int i=fnt;i<=n;i++)
            rs+=F(i-1,fnt-1)*gt[n-i]*C(n-1,n-i);
    return rs;
}

main()
{
      int time,rs;
      int n,fnt,bck;
      Giaithua();
      scanf("%d",&time);
      while (time>0)
      {
            scanf(" %d %d %d",&n,&fnt,&bck);
            rs=0;
            if (fnt<bck) Swap(&fnt,&bck);
            if (n==0 || fnt==0 || bck==0 || fnt+bck>n+1) rs=0;
            else if (bck==1)
                 {
                    if (fnt==1 && n==1) rs=1;
                    else rs=F(n-1,fnt-1);
                 }
            else
            {
                for (int i=fnt;i<=n-bck+1;i++)
                    rs+=F(i-1,fnt-1)*F(n-i,bck-1)*C(n-1,i-1);
            }
            printf("%d\n",rs);
      
    //        for (i=0;i<=12;i++)
  //              printf("%d ",gt[i]);
            time--;
      }
}
