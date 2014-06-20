#include <stdio.h>

int a[100000],b[100000],len1[100000],len2[100000];
int n;

int In()
{
     for (int i=1;i<=n;i++)
     {
         len1[i]=b[i];
         for (int j=i-1;j>=1;j--)
         {
             if (a[i]>a[j])
                if (b[i]+len1[j] > len1[i]) len1[i]=len1[j]+b[i];
         }
     }
     
     int max=len1[1];
     for (int i=2;i<=n;i++)
        if (len1[i]>max) max=len1[i];
     return max;
}

int De()
{
     for (int i=1;i<=n;i++)
     {
         len2[i]=b[i];
         for (int j=i-1;j>=1;j--)
         {
             if (a[i]<a[j])
                if (b[i]+len2[j] > len2[i]) len2[i]=len2[j]+b[i];
         }
     }
     
     int max=len2[1];
     for (int i=2;i<=n;i++)
        if (len2[i]>max) max=len2[i];
     return max;
}



main()
{
      int inc,dec, time,t,i;
      scanf("%d",&time);
      for (t=1;t<=time;t++)
      {
          scanf("%d",&n);
          for (i=1;i<=n;i++)
              scanf("%d",&a[i]);
          for (i=1;i<=n;i++)
              scanf("%d",&b[i]);
          
          inc=In(); dec=De();
          
          printf("Case %d. ",t);
          
          if (inc>=dec) printf("Increasing (%d). Decreasing (%d).\n",inc,dec);
          else printf("Decreasing (%d). Increasing (%d).\n",dec,inc);
          
      /*    for (i=1;i<=n;i++)
              printf("%d ",len1[i]);
          printf("\n");
          for (i=1;i<=n;i++)
              printf("%d ",len2[i]);
          printf("\n");  */
      }
}
