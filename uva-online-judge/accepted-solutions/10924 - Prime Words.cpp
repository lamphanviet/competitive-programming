// 10924 - Prime Words
#include <iostream>
#define N 2050

using namespace std;

main() {
    bool isP[N];
    int i, j, n, sum;
    char s[25];
    memset(isP, true, N);
    isP[0] = false;
    for (i=2; i<N; i++)
        if (isP[i])
            for (j=i+i; j<N; j+=i)
                isP[j] = false;
    while (gets(s)) {
        n = strlen(s);
        for (i=0, sum=0; i<n; i++)
            if (isupper(s[i])) sum += (int)s[i]-38;
            else sum += (int)s[i]-96;
        
        if (isP[sum]) cout << "It is a prime word.";
        else cout << "It is not a prime word.";
        cout << endl;
    }
}
