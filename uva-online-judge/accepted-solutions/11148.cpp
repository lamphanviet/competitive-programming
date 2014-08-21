#include <iostream>

using namespace std;

int tu,mau;
char s[100];

int Check(char a) {
    if (a>='0' && a<='9') return 1;
    return 0;
}

int UCLN(int a, int b) {
    if (a%b==0) return b;
    else return UCLN(b,a%b);
}

void Rutgon() {
    if (tu!=0) {
        int uc = UCLN(tu,mau);
        tu/=uc;
        mau/=uc;
    }
}

void Run() {
    int n = strlen(s);
    int i,j,k,hs;
    int num1,num2,num3;
    tu = mau = 1;
    k = 0;
    while (k<n) {
        if (Check(s[k])) {
            i = k+1;
            while (Check(s[i]) && i<n) i++;
            if (i==n || s[i]==' ' || s[i]=='/' || s[i]=='-') {
                num1 = 0;
                for (j=i-1,hs=1;j>=k;j--,hs*=10)
                    num1 += hs*(s[j]-48);
                
                k = i+1;
                if (s[i]==' ' || i==n) {
                    num2 = 1;
                }
                else if (s[i]=='/') {
                    i++;
                    while (Check(s[i]) && i<n) i++;
                    num2 = 0;
                    for (j=i-1,hs=1;j>=k;j--,hs*=10)
                        num2 += hs*(s[j]-48);
                    k = i+1;
                }
                else {          //s[i]=='-';
                    i++;
                    while (Check(s[i]) && i<n) i++;
                    num3=0;
                    for (j=i-1,hs=1;j>=k;j--,hs*=10)
                        num3 += hs*(s[j]-48);
                    k=++i;
                    while (Check(s[i]) && i<n) i++;
                    num2=0;
                    for (j=i-1,hs=1;j>=k;j--,hs*=10)
                        num2 += hs*(s[j]-48);
                    num1=num1*num2+num3;
                    k = i+1;
                }
                
                tu*=num1;
                mau*=num2;
            }
        }
        else k++;
    }
    Rutgon();
    if (tu==0) cout << 0;
    else if (mau==1) cout << tu;
    else if (tu<mau)
        cout << tu << "/" << mau;
    else {
        cout << tu/mau << "-";
        cout << tu%mau << "/" << mau;
    }
    cout << endl;
}

main() {
 //   freopen("48.inp","r",stdin);
 //   freopen("48.out","w",stdout);
    int kase;
    cin >> kase; scanf(" ");
    while (kase--) {
        gets(s);
        Run();
    }
}
