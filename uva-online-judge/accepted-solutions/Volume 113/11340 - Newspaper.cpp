//*****************
// LAM PHAN VIET **
// UVA 11340 - Newspaper
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

main() {
//    freopen("340.inp","r",stdin);
 //   freopen("340.out","w",stdout);
    int Case, i, n, len;
    double sum, c, cost[260];
    char s[10005], ch;
    cin >> Case;
    while (Case--) {
        for (i=0;i<=255;i++)
            cost[i] = 0.0;
        scanf("%d", &n);
        while (n--) {
            scanf(" %c %lf",&ch,&c);
      //      printf("%c %d",ch,c);
            cost[ch+128] = c;
        }
        scanf("%d", &n); getchar();
        sum = 0;
        while (n--) {
            gets(s);
            len = strlen(s);
            for (i=0;i<len;i++)
                sum += cost[s[i]+128];
        }
        printf("%.2lf$\n",sum/100.0);
    }
}

/* lamphanviet@gmail.com - 2011 */
