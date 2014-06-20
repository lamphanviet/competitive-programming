#include <stdio.h>
#include <string.h>

main()
{
      int i,j,time,n,rs;
      char a[10010];
      short int x[10010];
      int h[10010];
      
      scanf("%d",&time); getchar();
      while (time>0)
      {
            gets(a); n=strlen(a);
            if (a[0]=='/') x[0]=1;
            else if (a[0]=='\\') x[0]=-1;
            else x[0]=0;
            h[0]=x[0];
            
            for (i=1;i<n;i++)
            {
                if (a[i]=='/') x[i]=1;
                else if (a[i]=='\\') x[i]=-1;
                else x[i]=0;
                
                h[i]=h[i-1]+x[i];
            }
            
     /*       for (i=0;i<n;i++)
                printf("%3d",x[i]);
            printf("\n");
            for (i=0;i<n;i++)
                printf("%3d",h[i]);
            printf("\n");          */
            
            rs=0;
            
            for (i=0;i<n-1;i++)
                if (x[i]==-1)
                   for (j=i+1;j<n;j++)
                       if (x[j]==1 && h[i]==h[j]-1)
                       {
                          rs+=j-i;
                          break;
                       }
            printf("%d\n",rs);
            time--;
      }
}
