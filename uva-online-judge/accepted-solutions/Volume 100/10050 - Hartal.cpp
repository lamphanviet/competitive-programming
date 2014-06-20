#include <stdio.h>

main()
{
      int xtest, test, xday, day[3652], party, hartal[102];
      int count,i,j;
      scanf("%d",&xtest);
      for (test=1;test<=xtest;test++)
      {
          scanf("%d %d",&xday,&party);       //Nhap so ngay va so dang
          for (i=1;i<=party;i++)             //Nhap so hartal cua moi dang
              scanf("%d",&hartal[i]);
          for (i=1;i<=xday;i++)              //Cho gia tri cua day[i] la 0
              day[i]=0;
          for (i=1;i<=party;i++)
              for (j=hartal[i];j<=xday;j+=hartal[i])
                  day[j]=1;
          count=0;
          for (i=1;i<=xday;i++)
              if (day[i]==1 && (i-6)%7!=0 && i%7!=0)
                 count++;
          printf("%d\n",count);
      }
}
