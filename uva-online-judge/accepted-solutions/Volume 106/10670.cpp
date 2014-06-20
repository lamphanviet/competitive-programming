#include <stdio.h>
#include <string.h>

struct Agency {
    char name[20];
    int A,B,cost;
} a[110];

int ss,tag,n;

void Print() {
    for (int i=1;i<=n;i++)
        printf("%s: %d, %d\n",a[i].name,a[i].A,a[i].B);
    printf("\n");
}

void Enter() {
    int i,k,len;
    char x[50];
    scanf("%d %d %d",&ss,&tag,&n); getchar();
    for (i=1;i<=n;i++) {
        gets(x);
        k=0;
        while (x[k]!=':') {
            a[i].name[k]=x[k];
            x[k++]=' ';
        }
        a[i].name[k]='\0'; x[k]=' ';
        
        while (x[k]!=',') k++;
        x[k]=' ';
        sscanf(x,"%d %d",&a[i].A,&a[i].B);
        
        a[i].cost=0;
    }
//    Print();
}

void Sapxep() {
    Agency temp;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i].cost>a[j].cost || (a[i].cost==a[j].cost && strcmp(a[i].name,a[j].name)>0)) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}

void Process()
{
    int i,nn,temp;
    for (i=1;i<=n;i++) {
        nn=ss;
        while (nn>tag) {
            temp=nn/2;
            if (temp>=tag && a[i].B<=(nn-temp)*a[i].A) {
                a[i].cost+=a[i].B;
                nn=temp;
            }
            else {
                a[i].cost += (nn-tag)*a[i].A;
                nn=tag;
            }
        }
    }
}

void Result() {
    for (int i=1;i<=n;i++)
        printf("%s %d\n",a[i].name,a[i].cost);
}

main() {
//    freopen("670inp.txt","r",stdin);
//    freopen("670out.txt","w",stdout);
    
    int time;
    scanf("%d",&time);
    for (int t=1;t<=time;t++) {
        Enter();
        Process(); Sapxep();
        printf("Case %d\n",t);
        Result();
    }
}
