#include <stdio.h>

main()
{
    int time,a,n;
    scanf("%d",&time);
    for (int t=1;t<=time;t++)
    {
        scanf("%d",&n);
        int min=0;
        while (n-->0)
        {
            scanf("%d",&a);
            if (a>min) min=a;
        }
        printf("Case %d: %d\n",t,min);
    }
}
