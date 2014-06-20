#include <stdio.h>
#include <string.h>
#include <iostream>

struct Player
{
    char name[30];
    int at,df;
} p[12];

void Swap(int i, int j)
{
    Player tmp;
    tmp=p[i];
    p[i]=p[j];
    p[j]=tmp;
}
/*
void Swapname(int i, int j)
{
    char tmp[30];
    strcpy(tmp,p[i].name);
    strcpy(p[i].name,p[j].name);
    strcpy(p[j].name,tmp);
    
}
*/
void Sapxep1()
{
    for (int i=1;i<10;i++)
        for (int j=i+1;j<=10;j++)
            if (p[i].at<p[j].at) Swap(i,j);
            else if (p[i].at==p[j].at)
            {
                if (p[i].df>p[j].df) Swap(i,j);
                else if (p[i].df==p[j].df)
                {
                    if (strcmp(p[i].name,p[j].name)>0) Swap(i,j);
                }
            }
            
    for (int i=1;i<5;i++)
        for (int j=i+1;j<=5;j++)
            if (strcmp(p[i].name,p[j].name)>0) Swap(i,j);
        
    for (int i=6;i<10;i++)
        for (int j=i+1;j<=10;j++)
            if (strcmp(p[i].name,p[j].name)>0) Swap(i,j);
}


void Print()
{
    printf("(%s, %s, %s, %s, %s)\n",p[1].name,p[2].name,p[3].name,p[4].name,p[5].name);
    printf("(%s, %s, %s, %s, %s)\n",p[6].name,p[7].name,p[8].name,p[9].name,p[10].name);
}

main()
{
//    freopen("ainp.txt","r",stdin);
 //   freopen("aout.txt","w",stdout);
    
    int numcase;
    scanf("%d",&numcase);
    for (int t=1;t<=numcase;t++)
    {
        printf("Case %d:\n",t);
        for (int i=1;i<=10;i++)
        {
            getchar();
            scanf("%s %d %d",&p[i].name,&p[i].at,&p[i].df);
            
        }
        Sapxep1();
        Print();
    }
}
