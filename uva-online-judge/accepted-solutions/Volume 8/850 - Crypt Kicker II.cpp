#include <stdio.h>
#include <string.h>

#define Key "the quick brown fox jumps over the lazy dog"

int n,len[100],len_key,khoa_alp[126],khoa_inp[126];
char inp[110][85],new_alp[126];

int Get()
{
     int i=1;
     gets(inp[i]); len[i]=strlen(inp[i]);
     while (inp[i][0]!='\0')
     {
           i++;
           gets(inp[i]);
           len[i]=strlen(inp[i]);
     }
     return i-1;
}

int Find()
{
    int t,i;
    for (t=1;t<=n;t++)
    {
        if (len[t]==len_key && inp[t][3]==' ')
        {
           for (i=32;i<=125;i++)
           {
               khoa_alp[i]=khoa_inp[i]=0;
           }
            
           for (i=0;i<len_key;i++)
           {
               if (!khoa_inp[inp[t][i]] && !khoa_alp[Key[i]])
               {
                  new_alp[inp[t][i]] = Key[i];
                  khoa_inp[inp[t][i]]=khoa_alp[Key[i]]=1;
               }
               else if (new_alp[inp[t][i]]!=Key[i]) break;
           }
                  
           if (i==len_key) return t;
        }
    }
    return 0;
}

void Print()
{
     for (int t=1;t<=n;t++)
     {
         for (int i=0;i<len[t];i++)
             printf("%c",new_alp[inp[t][i]]);
         printf("\n");
     }
}

main()
{
      int time,k;
      len_key=strlen(Key);
      scanf("%d",&time); getchar(); getchar();
      while (time>0)
      {
            n=Get();
            k=Find();
            if (k==0) printf("No solution.\n");
            else Print();
            if (time!=1) printf("\n");
            time--;
      }
}
