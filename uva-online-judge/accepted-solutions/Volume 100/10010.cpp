#include <stdio.h>
#include <string.h>
#include <iostream>

char hang[32767][55];
char word[25][32767];
int wlen[25],n,len,nw;

int check(int t, int x, int y, int k)
{
    if (k==wlen[t])
    {
        printf("%d %d\n",x,y+1);
        return 1;
    }
    return 0;
}

int find(int t, int x, int y)
{
    int i=x,j=y,k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i--; j--; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i--; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i--; j++; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          j++; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i++; j++; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i++; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])      
    {
          i++; j--; k++;
    }
    if (check(t,x,y,k)) return 1;
    i=x; j=y; k=0;
    while (k<wlen[t] && hang[i][j]==word[t][k])          
    {
          j--; k++;
    }
    if (check(t,x,y,k)) return 1;

    return 0;
}

int main()
{
      int i,j,t,con,time;
      char temp[2];
      scanf("%d",&time);
      getchar();
      while (time>0)
      {
            scanf("%d %d",&n,&len); 
            getchar();
            for (i=0;i<=n+5;i++) memset(hang[i],0,sizeof(hang[i]));
            for (i=1;i<=n;i++)
            {
                gets(hang[i]);
                for (j=0;j<len;j++)
                    hang[i][j]=toupper(hang[i][j]);
            }
            scanf("%d",&nw); 
            getchar();
            for (i=1;i<=nw;i++)
            {
                gets(word[i]);
                wlen[i]=strlen(word[i]);
                for (j=0;j<wlen[i];j++)
                    word[i][j]=toupper(word[i][j]);
                    
                con=1;
                for (t=1;t<=n;t++)
                {
                    for (j=0;j<len;j++)
                    {
                        if (hang[t][j]==word[i][0])
                           if (find(i,t,j))
                           {
                              con=0;
                              break;
                           }
                    }
                    if (!con) break;
                }
            }
            
            if (time!=1) printf("\n");
            time--;
      }
      return 0;
}
