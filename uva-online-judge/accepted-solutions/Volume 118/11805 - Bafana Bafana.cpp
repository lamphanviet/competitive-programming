#include <stdio.h>

main()
{
    int time,n,k,p;
    scanf("%d",&time);
    for (int t=1;t<=time;t++)
    {
        scanf("%d %d %d",&n,&k,&p);
        while (p-->0)
        {
            if (k==n) k=1;
            else k++;
        }
        printf("Case %d: %d\n",t,k);
    }
}
