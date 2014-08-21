#include <stdio.h>

main()
{
    int n,t,time;
    scanf("%d",&time);
    for (t=1;t<=time;t++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",t);
        int a[50],j,i=0;
        if (n==0) printf("0");
        else
        {
            while (n!=0)
            {
                if (n%-2==0)
                {
                    a[++i]=0;
                    n=n/-2;
                }
                else
                {
                    a[++i]=1;
                    if (n<0) n=(n/-2)+1;
                    else n=n/-2;
                }
            }
            for (j=i;j>=1;j--)
                printf("%d",a[j]);
        }
        printf("\n");
    }
}
