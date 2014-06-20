#include <stdio.h>
#include <string.h>

int n,num,count;
char a[50];
int sao[50];

int Check_if_free(int lm)
{
    int i,j,k;
    if (lm<2) return 1;
    int tmp1=(lm+1)/3;
    for (i=1;i<=tmp1;i++)
    {
        int tmp2=lm+1-(3*i);
        for (j=0;j<=tmp2;j++)
        {
            int tmp3=i+j-1;
            for (k=j;k<=tmp3;k++)
                if (!(a[k]==a[k+i] && a[k+i]==a[k+i*2])) break;
            if (k==tmp3+1) return 0;
        }
    }
    return 1;
}

void BR(int k)
{
    if (k==num) count++;
    else
    {
        a[sao[k]]=49;
        if (Check_if_free(sao[k+1]-1)) BR(k+1);
        a[sao[k]]=48;
        if (Check_if_free(sao[k+1]-1)) BR(k+1);
    }
}

void Pre()
{
    int i;
    for (num=0,i=0;i<n;i++)
        if (a[i]=='*')
            sao[++num]=i;
    sao[++num]=n;
}

main()
{
  //  freopen("127inp.txt","r",stdin);
  //  freopen("127out.txt","w",stdout);
    int time=0;
    scanf("%d",&n);
    while (n!=0)
    {
        count=0;
        scanf("%s",&a);
        Pre();
        if (num==1)
        {
            if (Check_if_free(n-1)) count++;
        }
        else BR(1);
        printf("Case %d: %d\n",++time,count);
        scanf("%d",&n);
    }
}
