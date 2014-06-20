// 10098 - Generating Fast, Sorted Permutation
#include <iostream>

using namespace std;

main() {
    int kase, len;
    char str[12];
    cin >> kase; cin.get();
    while (kase--) {
        gets(str);
        len = strlen(str);
        sort(str,str+len);
        do {
            puts(str);
        } while (next_permutation(str,str+len));
        cout << endl;
    }
}
