// 10008 - What's Cryptanalysis?
#include <iostream>

using namespace std;

struct Ans {
    char alp;
    int num;
} ans[30];

bool cmp(Ans a, Ans b) {
    return (a.num > b.num);
}

main() {
    char str[100];
    int n, i, len;
    for (i=0; i<30; i++) {
        ans[i].num = 0;
        ans[i].alp = (char)(i+65);
    }
    cin >> n; cin.get();
    while (n--) {
        gets(str); len = strlen(str);
        for (i=0; i<len; i++)
            if (isalpha(str[i]))
                ans[toupper(str[i])-'A'].num++;
    }
    
    stable_sort(ans, ans+26, cmp);
    for (i=0; i<30 && ans[i].num>0; i++)
        printf("%c %d\n", ans[i].alp, ans[i].num);
//    system("pause");
}
