#include <stdio.h>
#include <string.h>

#define INF 3000

int n,dis,km[1000],mn[1000];

void Inp2()
{
    char temp[256],len;
    n=0;
    scanf("%d",&dis); getchar();
    while (fgets(temp,256,stdin) && strlen(temp)!=1)
    {
        n++;
        sscanf(temp,"%d %d",&km[n],&mn[n]);
    }
}

void Print()
{
    for (int i=1;i<=n;i++)
        printf("%d %d\n",km[i],mn[i]);
}

int Run()
{
    int money=0,i,j;
    if (dis==0) return 0;
    if (dis>km[n])
        if (dis-km[n]>100) return -1;
        else
        {
            n++;
            km[n]=dis; mn[n]=INF;
        }
    else if (dis<km[n])
    {
        i=n;
        while (km[i]>dis) i--;
        if (km[i]==dis) n=i;
        else
        {
            if (dis-km[i]>100) return -1;
            else
            {
                n=i+1;
                km[n]=dis; mn[n]=INF;
            }
        }
    }
    
    int gas=100-km[1];
    if (gas<0) return -1;
    
    if (n==1 && mn[1]!=INF) return (100-gas)*mn[1];
    else if (n==1 && mn[1]==INF) return -1;
    
    for (i=1;i<=n;i++)
    {
        if (i==n)
        {
            if (gas<100) money += (100-gas)*mn[n];
            return money;
        }
        
        if (km[i+1]-km[i]>200) return -1;
        
        j=i;
        while (j<n && mn[j]>=mn[i] && km[j]-km[i]<200) j++;
        
        if (mn[j]>=mn[i]) j=i;
        
        if (j==i)
        {
            if (km[n]-km[i]<=100)
            {
                money += (100+km[n]-km[i]-gas)*mn[i];
                return money;
            }
            else
            {
                money += (200-gas)*mn[i];
                gas=200-(km[i+1]-km[i]);
            }
        }
        else
        {
            if (km[j]-km[i]>=gas)
            {
                money += (km[j]-km[i]-gas)*mn[i];
                gas=0;
            }
            else gas=gas-(km[j]-km[i]);
            i=j-1;
        }
    }
    return money;
}


main()
{
   // freopen("10201inp.txt","r",stdin);
//    freopen("10201out.txt","w",stdout);
    int time,rs;
    km[0]=mn[0]=0;
    scanf("%d",&time);
    while (time>0)
    {
        Inp2();
 //       Print();
        rs=Run();
        if (rs==-1) printf("Impossible\n");
        else printf("%d\n",rs);
        if (time!=1) printf("\n");
        time--;
    }
}
