#include <stdio.h>
#include <iostream>

main()
{
    bool lock[101];
    int i,t,n,count,k;
    scanf("%d",&n);
    while (n!=0)
    {
        int con=0;
        for (t=1;t<=n;t++)
        {
            memset(lock,false,n+2);
            k=0; count=t-1;
            for (i=1;i<=n;i++)
            {
                if (!lock[i])
                {
                    count++;
                    if (count==t)
                    {
                        lock[i]=true;
                        k++;
                        count=0;
                        if (i==13)
                        {
                            if (k==n) con=1;
                            break;
                        }
                    }
                }
                if (i==n) i=0;
            }
            
            if (con)
            {
                printf("%d\n",t);
                break;
            }
        }
        scanf("%d",&n);
    }
}
