// 10905 - Children's Game
#include <iostream>
#include <string>

using namespace std;

bool cmp(string a, string b){
    string x = a+b;
    string y = b+a;
    return (x>y);
}

main() {
    int n, i;
    char line[10];
    string a[55];
    while (scanf("%d", &n) && n) {
        gets(line);
        for (i=0; i<n; i++) cin >> a[i];
        sort(a, a+n, cmp);
        for (i=0; i<n; i++) cout << a[i];
        cout << endl;
    }
}
