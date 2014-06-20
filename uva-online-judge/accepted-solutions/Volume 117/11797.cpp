#include <stdio.h>
#include <iostream>
#include <string.h>

char name[7][5];
int n,m,list[7][30],who,ttime[7];

void Khoitao()
{
    strcpy(name[1],"Ja");
    strcpy(name[2],"Sam");
    strcpy(name[3],"Sha");
    strcpy(name[4],"Sid");
    strcpy(name[5],"Tan");
}

void Reset()
{
    for (int i=1;i<=5;i++)
        ttime[i]=0;
}

int Convert(char x[])
{
    if (x[0]=='J') return 1;
    if (x[2]=='m') return 2;
    if (x[1]=='h') return 3;
    if (x[2]=='d') return 4;
    return 5;
}

void Inp_List()
{
    int i,j;
    char x[7];
    
    for (i=1;i<=5;i++)
    {
        scanf("%d",&list[i][0]); getchar();
        for (j=1;j<=list[i][0];j++)
        {
            scanf("%s",&x);
            list[i][j]=Convert(x);
        }
            
    }
}


void Run()
{
    int t=0,next,i,j;
    while (t<n)
    {
        if (t+m<=n) ttime[who]+=m;
        else ttime[who]+=(n-t);
        
        next=list[who][1];
        
        for (i=2;i<=list[who][0];i++)
            list[who][i-1]=list[who][i];
        list[who][list[who][0]]=next;
        
//        printf("who %d\n",who);
 //       for (i=1;i<=list[who][0];i++)
 //           printf("%d ",list[who][i]);
 //       printf("\n");
        
        who=next;
        t += (m+2);
    }
}

void Print()
{
    printf("%d\n",who);
    for (int i=1;i<=5;i++)
    {
        printf("%d",list[i][0]);
        for (int j=1;j<=list[i][0];j++)
            printf(" %s",name[list[i][j]]);
        printf("\n");
    }
}

void Out_Result(int test)
{
    printf("Case %d:\n",test);
    for (int i=1;i<=5;i++)
        printf("%s %d\n",name[i],ttime[i]);
}

main()
{
    freopen("dinp.txt","r",stdin);
    freopen("dout.txt","w",stdout);
    int numcase;
    Khoitao();
    scanf("%d",&numcase);
    for (int t=1;t<=numcase;t++)
    {
        char tmp[7];
        Reset();
        scanf("%d %d %s",&m,&n,tmp);
 //       printf("%d %d\n",m,n);
        who=Convert(tmp);
        Inp_List();
        Run();
        Out_Result(t);
//        Print();
    }
}
