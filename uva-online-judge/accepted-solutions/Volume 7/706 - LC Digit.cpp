#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ifEnd(int s, char n[])
{
    if (s==0 && n[0]=='0') return 1;
    else return 0;
}

int read(int *s,char n[])
{
    int i;
    scanf("%d ",s);
    gets(n);
    return ifEnd(*s,n);
}

void printline(char line[], int s)
{
     int i;
     for (i=0;i<s;i++)
         printf("%c",line[i]);
}

int main()
{
    char n[10],both[15],mid[15],left[15],right[15],space[15];
    int s,i,len,height,j;
    int isEnd = read(&s,n);

    while (!isEnd)
    {
          space[0]=' '; space[s+1]=' ';
          mid[0]=' '; mid[s+1]=' ';
          both[0]='|'; both[s+1]='|';
          right[0]=' '; right[s+1]='|';
          left[0]='|'; left[s+1]=' ';
          for (i=1;i<=s;i++) {
              space[i]=' ';
              mid[i]='-';
              both[i]=' ';
              left[i]=' ';
              right[i]=' ';
          }
          
          len=strlen(n);
          height=2*s+3;
          for (i=1;i<=height;i++)
          {
              for (j=0;j<len;j++) {
                  if (((i==1 || i==height || i==s+2)&&(n[j]=='2' || n[j]=='3' || n[j]=='5' || n[j]=='6' || n[j]=='8' || n[j]=='9' )) || (n[j]=='4' && i==s+2) || (n[j]=='0' && (i==1 || i==height)) || (n[j]=='7' && i==1))
                  {
                     printline(mid,s+2);
                     if (j!=len-1) printf(" ");
                  }
                  if ((i>=2 && i<=s+1 && (n[j]=='6' || n[j]=='5')) || (i>=s+3 && i<=height-1 && n[j]=='2'))
                  {
                     printline(left,s+2);
                     if (j!=len-1) printf(" ");
                  }
                  if (((n[j]=='1' || n[j]=='7' || n[j]=='0') && i==s+2) || ((n[j]=='1' || n[j]=='4')&&(i==1 || i==height)) || (n[j]=='7' && i==height)) 
                  {
                     printline(space,s+2);
                     if (j!=len-1) printf(" ");
                  }
                  if (((i>=2 && i<=s+1)&&(n[j]=='3' || n[j]=='7' || n[j]=='2' || n[j]=='1')) || ((i>=s+3 && i<=height-1)&&(n[j]=='1' || n[j]=='3' || n[j]=='4' || n[j]=='5' || n[j]=='7' || n[j]=='9')))
                  {
                     printline(right,s+2);
                     if (j!=len-1) printf(" ");
                  }
                  if (((i>=2 && i<=s+1)&&(n[j]=='4' || n[j]=='8' || n[j]=='9' || n[j]=='0')) || ((i>=s+3 && i<=height-1)&&(n[j]=='6' || n[j]=='8' || n[j]=='0')))
                  {
                     printline(both,s+2);
                     if (j!=len-1) printf(" ");
                  }
              }
              printf("\n");
          }
          printf("\n");
          isEnd = read(&s,n);
    }
}
                  
          
          
