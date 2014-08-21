#include <stdio.h>
#include <string.h>

char out[9][10];

void Pre()
{
    strcpy(out[1],"1");
    strcpy(out[2],"22");
    strcpy(out[3],"333");
    strcpy(out[4],"4444");
    strcpy(out[5],"55555");
    strcpy(out[6],"666666");
    strcpy(out[7],"7777777");
    strcpy(out[8],"88888888");
    strcpy(out[9],"999999999");
}



main()
{
    int time,amp,fre;
    Pre();
    scanf("%d",&time);
    while (time-->0)
    {
        scanf("%d %d",&amp,&fre);
        while (fre-->0)
        {
            for (int i=1;i<=amp;i++)
                puts(out[i]);
            for (int i=amp-1;i>=1;i--)
                puts(out[i]);
            if (fre!=0) printf("\n");
        }
        if (time!=0) printf("\n");
    }
}
