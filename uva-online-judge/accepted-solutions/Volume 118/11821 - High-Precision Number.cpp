#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
    int digit[85];
    int sign;
} Num;

Num a[110];
int n;

void Enter() {
    char s[35];
    int i,j,k,len,mid;
    n = 0;
    while (gets(s)) {
        len = strlen(s);
        if (len==1 && s[0]=='0') break;
        n++;
        if (s[0]=='-') a[n].sign = -1;
        else a[n].sign = 1;
        
        mid = 0;
        while (mid<len && s[mid]!='.') mid++;
        int temp;
        if (mid<len) temp = 40-(len-mid-1);
        else temp = 40;
        for (i=1;i<=temp;i++) a[n].digit[i] = 0;
        for (j=len-1;j>=mid+1;i++,j--) a[n].digit[i] = s[j]-48;
        
        if (a[n].sign==-1) k = 1;
        else k = 0;
        for (j=mid-1;j>=k;i++,j--) a[n].digit[i] = s[j]-48;
        temp = 40-mid;
        for (;i<=80;i++) a[n].digit[i] = 0;
    }
}


void Print() {
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=80;j>=1;j--)
            cout << a[i].digit[j];
        cout << endl;
    }
}

int SS(Num a, Num b) {
    for (int i=80;i>=1;i--)
        if (a.digit[i]>b.digit[i]) return 1;
        else if (a.digit[i]<b.digit[i]) return 0;
    return -1;
}

void Go() {
    Num G,temp;
    int i,j,k,m,du;
    
    G = a[1];
    for (k=2;k<=n;k++) {
        int sign = a[k].sign*G.sign;
        if (sign>0) {
            du = 0;
            for (i=1;i<=80;i++) {
                m = G.digit[i]+a[k].digit[i]+du;
                G.digit[i] = m%10;
                du = m/10;
            }
        }
        else {
            int big = SS(G,a[k]);
            if (big==1) {
                du = 0;
                for (i=1;i<=80;i++) {
                    a[k].digit[i] += du;
                    G.digit[i] = G.digit[i]-a[k].digit[i];
                    if (G.digit[i]<0) {
                        G.digit[i] += 10;
                        du = 1;
                    }
                    else du = 0;
                }
            }
            else if (big==0) {
                du = 0;
                for (i=1;i<=80;i++) {
                    G.digit[i] += du;
                    a[k].digit[i] = a[k].digit[i]-G.digit[i];
                    if (a[k].digit[i]<0) {
                        a[k].digit[i] += 10;
                        du = 1;
                    }
                    else du = 0;
                }
                G = a[k];
            }
            else {
                for (i=1;i<=80;i++) G.digit[i]=0;
                G.sign=1;
            }
        }
    }
    
    
    if (G.sign<0) cout << "-";
    while (G.digit[i]==0 && i>41) i--;
    for (;i>=41;i--)   cout << G.digit[i];
    k = 1;
    while (G.digit[k]==0 && k!=41) k++;
    if (k!=41) {
        cout << ".";
        for (;i>=k;i--) cout << G.digit[i];
    }
    cout << endl;
}

main() {
//    freopen("dd.inp","r",stdin);
//    freopen("dd.out","w",stdout);
    
    int kase;
    cin >> kase;
    getchar();
    while (kase--) {
        Enter();
 //       Print();
        Go();
 //       cout << endl;
    }
}
