#include <stdio.h>

static int Num_Dinh[] = {1,2,4,8,16,32,64,128,256,512,1024};
int n,socanh,a[5133][3],cnt[1025];

int Check_Bit(int a, int b)                                    //Kiem tra Bit
{
    int lech=0;
    while (a!=0 || b!=0)
    {
          if (a%2 != b%2) lech++;
          a/=2; b/=2;
          if (lech>1) return 0;
    }
    return 1;
    
}

int Check()
{
    int i,t;
    for (t=0;t<=10;t++)                                        //Kiem tra So dinh
        if (n==Num_Dinh[t]) break;
    if (t>10) return 0;
    
    for (i=1;i<=socanh;i++)                                    //Bit
        if (!Check_Bit(a[i][1],a[i][2])) return 0;
    
    for (i=0;i<n;i++)                                          //Kiem tra Noi
        cnt[i]=0;
    for (i=1;i<=socanh;i++)
    {
        cnt[a[i][1]]++;
        cnt[a[i][2]]++;
    }
    for (i=0;i<n;i++)
        if (cnt[i]!=t) return 0;
    return 1;
}

main()
{
      int i;
      scanf("%d %d",&n,&socanh);
      while (n!=0)
      {
            for (i=1;i<=socanh;i++)
                scanf("%d %d",&a[i][1],&a[i][2]);
            if (Check()) printf("YES\n");
            else printf("NO\n");
            scanf("%d %d",&n,&socanh);
      }
}
