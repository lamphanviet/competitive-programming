#include <stdio.h>
#include <string.h>

main()
{
  //  freopen("inp661.txt","r",stdin);
//    freopen("out661.txt","w",stdout);
    int len,i,t,min;
    char way[2000010],temp;
    scanf("%d",&len);
    while (len>0)
    {
        getchar(); gets(way);
        min=2000010; t=0;
        while (way[t]=='.') t++;
        if (way[t]=='Z') min=0;
        else
        {
            temp=way[t];
            for (i=t+1;i<len;i++)
                if (way[i]!='.')
                {
                    if (way[i]=='Z')
                    {
                        min=0;
                        break;
                    }
                    if (way[i]!=temp)
                    {
                        if (i-t<min)
                            min=i-t;
                    }
                    t=i;
                    temp=way[i];
                }
        }
        printf("%d\n",min);
        scanf("%d",&len);
    }
}
