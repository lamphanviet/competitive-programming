// 	11387 - The 3-Regular Graph
#include <iostream>

using namespace std;

main() {
    int n, i;
    while (cin >> n && n) {
        if (n%2 || n<4) printf("Impossible\n");
        else {
            cout << n*6/4 << endl;
            i = 1;
            if (n%4) {
                printf("1 2\n");
                printf("1 3\n");
                printf("1 4\n");
                printf("2 5\n");
                printf("2 6\n");
                printf("3 4\n");
                printf("3 5\n");
                printf("4 6\n");
                printf("5 6\n");
                i = 7;
            }
            for (;i<=n;i+=4) {
                printf("%d %d\n",i,i+1);
                printf("%d %d\n",i,i+2);
                printf("%d %d\n",i,i+3);
                printf("%d %d\n",i+1,i+2);
                printf("%d %d\n",i+1,i+3);
                printf("%d %d\n",i+2,i+3);
            }
        }
    }
}
