#include <stdio.h>

unsigned int Cnt(unsigned int n)
{
    int count=1;
    while (n!=1)
    {
        if (n%2!=0) n=3*n+1;
        else n=n/2;
        count++;
    }
    
    return count;
}

main()
{
    unsigned int a,b,count,max,i;
    while (scanf("%d %d",&a,&b)!=EOF)
    {
        max=0;
        printf("%d %d",a,b);
        if (a>b)
        {
            i=a;
            a=b;
            b=i;
        }
        for (i=a;i<=b;i++)
        {
            count=Cnt(i);
            if (max<count) max=count;
        }
        printf(" %d\n",max);
    }
}
