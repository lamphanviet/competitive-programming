// Problem 694 - The Collatz Sequence
#include <iostream>

using namespace std;

main() {
    int count,kase=0;
    long a,limit;
    while ((cin >> a >> limit) && a>=0 && limit>=0) {
        long A=a;
        count = 0;
        while (a<=limit) {
            count++;
            if (a==1) break;
            if (a%2==0) a/=2;
            else a = a*3+1;
        }
        cout << "Case " << ++kase << ": A = " << A << ", limit = " << limit << ", number of terms = " << count << endl;
    }
}
