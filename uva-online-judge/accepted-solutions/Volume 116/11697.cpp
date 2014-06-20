#include <stdio.h>
#include <string.h>
#include <iostream>

int tb[7][7];
bool lock[130];
char key[1010],msg[1010];

struct Position
{
    int x,y;
}   pos[125];

void Table()
{
    char temp[30];
    int n=strlen(key),t=0,i,j;
    memset(lock,false,125); lock[113]=true;      //Khoa ky tu 'q'
    
    for (i=0;i<n && t<25;i++)
        if (key[i]!=' ' && !lock[key[i]])
        {
            temp[t++]=key[i];
            lock[key[i]]=true;
        }
            
    for (i=97;i<=122;i++)
        if (!lock[i])
        {
            temp[t++]=i;
            lock[i]=true;
        }
        
    t=0;
    for (i=1;i<=5;i++)
        for (j=1;j<=5;j++)
        {
            tb[i][j]=temp[t++];
            pos[tb[i][j]].x=i;
            pos[tb[i][j]].y=j;
        }
}

void Print()
{
    for (int i=1;i<=5;i++)
    {
        for (int j=1;j<=5;j++)
            printf("%c  ",tb[i][j]);
        printf("\n");
    }
}

void MH(int a,int b)
{
    int ka,kb;
    
    if (pos[a].x==pos[b].x)
    {
        if (pos[a].y==5) ka=1;
        else ka=pos[a].y+1;
        if (pos[b].y==5) kb=1;
        else kb=pos[b].y+1;
        
        printf("%c%c",tb[pos[a].x][ka]-32,tb[pos[b].x][kb]-32);
    }
    else if (pos[a].y==pos[b].y)
    {
        if (pos[a].x==5) ka=1;
        else ka=pos[a].x+1;
        if (pos[b].x==5) kb=1;
        else kb=pos[b].x+1;
        
        printf("%c%c",tb[ka][pos[a].y]-32,tb[kb][pos[b].y]-32);
    }
    else
        printf("%c%c",tb[pos[a].x][pos[b].y]-32,tb[pos[b].x][pos[a].y]-32);
}

void Check()
{
    int n=strlen(msg),i=0,ch;
    while (i<n)
    {
        while (msg[i]==' ') i++;
        ch=msg[i];
        if (i==n-1)
        {
            MH(ch,'x');
            break;
        }
        while (msg[++i]==' ');
        if (msg[i]==ch) MH(ch,'x');
        else
        {
            MH(ch,msg[i]);
            i++;
        }
    }
}

main()
{
    int time;
    scanf("%d",&time); getchar();
    while (time>0)
    {
        gets(key); gets(msg);
        Table();
   //     Print();
        Check();
        printf("\n");
        time--;
    }
}
