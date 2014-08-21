#include <stdio.h>

int count,rd[120];

bool Check(int n)
{
    int i;
    if (n==0)
    {
        count++;
        return false;
    }
    for (i=0;i<count;i++)
        if (n==rd[i]) return false;
    count++; rd[i]=n;
    return true;
}

void F(int n)
{
    n=n*n;
    n=n/100;
    n=n%10000;
    if (Check(n)) F(n);
}

main()
{
    int n;
    scanf("%d",&n);
    while (n>0)
    {
        count=1; rd[0]=n;
        F(n);
        printf("%d\n",count);
        scanf("%d",&n);
    }
}
