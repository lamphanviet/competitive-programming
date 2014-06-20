// 11541 - Decoding
#include <iostream>

using namespace std;

main() {
    int kase, i, n, len, rp;
    char str[55], ch;
    scanf("%d", &kase); getchar();
    for (int k=1; k<=kase; k++) {
        gets(str); n = strlen(str);
        printf("Case %d: ", k);
        i = 0;
        while (i<n) {
            sscanf(str+i, "%c", &ch);
            i++;
            sscanf(str+i, "%d", &rp);
            while (rp--) printf("%c", ch);
            while (i<n && isdigit(str[i])) i++;
        }
        cout << endl;
    }
}
