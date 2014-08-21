#include <stdio.h>
#include <math.h>

unsigned long lt2[32],lt3[32];
unsigned long n;

void Khoitao()
{
    lt2[0]=lt3[0]=1;
    for (int i=1;i<=31;i++)
        lt2[i]=2*lt2[i-1];
    for (int i=1;i<=20;i++)
        lt3[i]=3*lt3[i-1];
}

unsigned long F()
{
    int k=-1,i3,i2=-1;
    while (k<20 && lt3[++k]<=n);
    if (lt3[k]==n) return n;
    
    unsigned long min=lt3[k];
    for (i3=k-1;i3>=0;i3--)
    {
        while (lt3[i3]*lt2[++i2]<n);
        if (lt3[i3]*lt2[i2]<min) min=lt3[i3]*lt2[i2];
    }
    return min;
}

main()
{
    Khoitao();
    scanf("%ld",&n);
    while (n>0)
    {
        printf("%ld\n",F());
        scanf("%ld",&n);
    }
}
