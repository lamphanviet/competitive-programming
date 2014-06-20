//725 - Division

#include <iostream>

using namespace std;

char a[32350][7], temp[7];
int N=0, n;
bool exist, Free[15];

void Generate(int n) {
    if (n==5) {
        strcpy(a[N++], temp);
        return;
    }
    for (int i=0; i<=9; i++)
        if (Free[i]) {
            Free[i] = false;
            temp[n] = i+'0';
            Generate(n+1);
            Free[i] = true;
        }
}

void Check(char snd[], int mul) {
    int i;
    char fir[7]; fir[5] = '\0';
    memset(Free, true, 10);
    for (i=0; i<5; i++) {
        Free[snd[i]-48] = false;
        fir[4-i] = char(mul%10)+'0'; mul/=10;
    }
    for (i=0; i<5; i++) {
        int k = fir[i]-48;
        if (Free[k]) Free[k] = false;
        else return;
    }
    
    exist = true;
    printf("%s / %s = %d\n", fir, snd, n);
}

main() {
    bool End = false;
    memset(Free, true, 10);
    temp[5] = '\0';
    Generate(0);
    while (cin >> n && n) {
        if (End) cout << endl; End = true;
        exist = false;
        for (int i=0; i<N; i++) {
            int num = n*atoi(a[i]);
            if (num<98766)
                Check(a[i], num);
        }
        
        if (!exist) printf("There are no solutions for %d.\n", n);
    }
}
