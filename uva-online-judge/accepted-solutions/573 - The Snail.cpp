// 573 - The Snail
#include <iostream>

using namespace std;

main() {
    int count;
    double height, night, day, percent, h;
    bool success;
    while (cin >> height >> day >> night >> percent) {
        if (height==0) break;
        count = 0;
        h = 0;
        percent = day*percent/100;
        while (1) {
            count++;
            h += day;
            day -= percent;
            if (day<0) day = 0;
            if (h>height) {
                success = true; break;
            }
            h -= night;
            if (h<0) {
                success = false; break;
            }
        }
        if (success) cout << "success";
        else cout << "failure";
        cout << " on day " << count << endl;
    }
}
