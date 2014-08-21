#include <stdio.h>
#include <string.h>

struct 
{
    char name[15],x1[15],x2[15],rs[5005];
    bool dau;
    int v1,v2;
} a[55];

int n;

int Convert(char name[30],int k)
{
    int len=strlen(name),i;
    for (i=1;i<k;i++)
        if (strcmp(name,a[i].name)==0) return i;
    return 1;
}

void Enter() {
    char temp[3],dau[3];
    getchar();
    for (int i=1;i<=n;i++) {
        scanf("%s %s %s %s %s",&a[i].name,&temp,&a[i].x1,&dau,&a[i].x2);
 //       printf("%s %s %s %s %s\n",a[i].name,temp,a[i].x1,dau,a[i].x2);
        if (dau[0]=='*') a[i].dau=1;
        else a[i].dau=0; //dau * la 1; dau + la 0;
        
        a[i].v1=a[i].v2=0;
        if ((a[i].x1[0]>='A' && a[i].x1[0]<='Z' )||( a[i].x1[0]>='a' && a[i].x1[0]<='z')) a[i].v1=Convert(a[i].x1,i);
        if ((a[i].x2[0]>='A' && a[i].x2[0]<='Z' )||( a[i].x2[0]>='a' && a[i].x2[0]<='z')) a[i].v2=Convert(a[i].x2,i);
        a[i].rs[0]='\0';
    }
}

void Result() {
    for (int i=1;i<=n;i++)
    {
        bool ng=0;
        if (a[i].v1!=0) {
            if (a[i].dau && a[a[i].v1].dau==0) {
                strcat(a[i].rs,"(");
                ng=1;
            }
            strcat(a[i].rs,a[a[i].v1].rs);
        }
        else strcat(a[i].rs,a[i].x1);
        if (ng) strcat(a[i].rs,")");
        ng=0;
        if (a[i].dau) strcat(a[i].rs,"*");
        else strcat(a[i].rs,"+");
        if (a[i].v2!=0) {
            if (a[i].dau) {
                strcat(a[i].rs,"(");
                ng=1;
            }
            else if (a[a[i].v2].dau==0) {
                strcat(a[i].rs,"(");
                ng=1;
            }
            strcat(a[i].rs,a[a[i].v2].rs);
        }
        else strcat(a[i].rs,a[i].x2);
        if (ng) strcat(a[i].rs,")");
    }
//    for (int i=1;i<=n;i++)
//        printf("%s = %s\n",a[i].name,a[i].rs);
}

main() {
 //   freopen("906inp.txt","r",stdin);
//    freopen("906out.txt","w",stdout);
    int time;
    scanf("%d",&time);
    for (int t=1;t<=time;t++) {
        scanf("%d",&n);
        Enter(); Result();
        printf("Expression #%d: %s\n",t,a[n].rs);
    }
}
