// Problem 10098 - Generating Fast
#include <iostream>
#include <string.h>

using namespace std;

char s[12],x[12];
bool a[12];
int n;

void Sort() {
    char temp;
    int i,j;
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if (s[i]>s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}

void Generate(int k) {
    int i,f=1;
    if (k==n) puts(x);
    else {
     for (i=0;i<n;i++)
        if (a[i]) {
            f = 0;
            a[i]=false;
            x[k] = s[i];
            Generate(k+1);
            a[i]=true;
        }
     }
}

main() {
    int kase;
    cin >> kase;
    scanf(" ");
    while (kase--) {
        gets(s);
        n = strlen(s);
        Sort();
        memset(a,true,n+1);
        x[n]='\0';
        Generate(0);
        cout << endl;
    }
}
