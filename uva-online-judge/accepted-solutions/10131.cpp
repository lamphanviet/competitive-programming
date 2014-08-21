#include <stdio.h>
#include <iostream>

int n;
int len[1010],from[1010];

struct Elephant
{
       int m;
       int iq;
       int stt;
} elp[1010];

void Sapxep_iq()
{
     Elephant temp;
     for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
             if (elp[i].iq<elp[j].iq)
             {
                temp=elp[i];
                elp[i]=elp[j];
                elp[j]=temp;
             }
}

void Quyhoach()
{
     int i,j;
     len[1]=1;
     from[1]=0;
     for (i=2;i<=n;i++)
     {
         len[i]=1;
         from[i]=0;
         for (j=i-1;j>=1;j--)
             if (elp[i].m>elp[j].m && len[i]<=len[j] && elp[i].iq!=elp[j].iq)
             {
                len[i]=len[j]+1;
                from[i]=j;
             }
     }
}

int VT_Max()
{
     int k=1,max=len[1];
     for (int i=2;i<=n;i++)
         if (len[i]>max)
         {
            max=len[i];
            k=i;
         }
     return k;
}

void Inkq()
{
     int i,m=1,k,out[1010];
     k=VT_Max();
     printf("%d\n",len[k]);
     do
     {
           out[m]=elp[k].stt;
           k=from[k];
           m++;
     } while (k!=0);
     for (i=m-1;i>=1;i--)
         printf("%d\n",out[i]);
}

main()
{
      int i;
      n=1;
      while (scanf("%d %d",&elp[n].m,&elp[n].iq)!=EOF)
            n++;
      for (i=1;i<=n;i++)
          elp[i].stt=i;
          
      Sapxep_iq();
      Quyhoach();
      Inkq();
}
