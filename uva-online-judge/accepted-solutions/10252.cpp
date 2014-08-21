#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

main()
{
      char str1[1010], str2[1010];
      int x1[125],x2[125];
      int i,n1,n2;
      
      while (gets(str1)&& gets(str2))
      {
            n1=strlen(str1); n2=strlen(str2);
            memset(x1,0,sizeof(x1));
            memset(x2,0,sizeof(x2));
            
            for (i=0;i<=n1;i++)
                x1[str1[i]]++;
            for (i=0;i<=n2;i++)
                x2[str2[i]]++;
            
            for (i='a';i<='z';i++)
                if (x1[i]!=0 && x2[i]!=0)
                {
                   printf("%c",i);
                   x1[i]--; x2[i]--;
                   i--;
                }
            printf("\n");
      }
}
