#include <stdio.h>

main()
{
    unsigned long a,b;
    while (scanf("%ld %ld",&a,&b)!=EOF)
    {
        if (a>b) printf("%ld\n",a-b);
        else printf("%ld\n",b-a);
    }
}
