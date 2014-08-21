// Problem 10098 - Generating Fast
#include <iostream>
#include <string.h>

using namespace std;

char s[12];
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

void Generate() {
    int i,k, a,b;
    char temp;
    while (i>=0) {
        puts(s);
        i = n-2;
        while (i>=0 && s[i]>s[i+1]) i--;
        if (i>=0) {
            k = n-1;
            while (s[k]<s[i]) k--;
            // Swap s[k] s[i]
            temp = s[k]; s[k] = s[i]; s[i] = temp;
            a = i+1;
            b = n-1;
            while (a<b) {
                temp = s[a]; s[a] = s[b]; s[b] = temp;
                a++; b--;
            }
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
        Generate();
        cout << endl;
    }
}
