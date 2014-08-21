/*****************/
/* LAM PHAN VIET */
/* UVA
/* Time limit:
/********************************/
#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {
        printf("%d\n", (n-1 + n*(m-1)));
    }
    return 0;
}
