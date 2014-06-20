// 11223 - O: dah dah dah!
#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, char> data;

void Data() {
    data[".-"] = 'A';       data[".---"] = 'J';     data["..."] = 'S';      data[".----"] = '1';    data[".-.-.-"] = '.';    data["---..."] = ':';
    data["-..."] = 'B';     data["-.-"] = 'K';      data["-"] = 'T';        data["..---"] = '2';    data["--..--"] = ',';    data["-.-.-."] = ';';
    data["-.-."] = 'C';     data[".-.."] = 'L';     data["..-"] = 'U';      data["...--"] = '3';    data["..--.."] = '?';    data["-...-"] = '=';
    data["-.."] = 'D';      data["--"] = 'M';       data["...-"] = 'V';     data["....-"] = '4';    data[".----."] = '\'';   data[".-.-."] = '+';
    data["."] = 'E';        data["-."] = 'N';       data[".--"] = 'W';      data["....."] = '5';    data["-.-.--"] = '!';    data["-....-"] = '-';
    data["..-."] = 'F';     data["---"] = 'O';      data["-..-"] = 'X';     data["-...."] = '6';    data["-..-."] = '/';     data["..--.-"] = '_';
    data["--."] = 'G';      data[".--."] = 'P';     data["-.--"] = 'Y';     data["--..."] = '7';    data["-.--."] = '(';     data[".-..-."] = '"';
    data["...."] = 'H';     data["--.-"] = 'Q';     data["--.."] = 'Z';     data["---.."] = '8';    data["-.--.-"] = ')';    data[".--.-."] = '@';
    data[".."] = 'I';       data[".-."] = 'R';      data["-----"] = '0';    data["----."] = '9';    data[".-..."] = '&';  
}

main() {
//    freopen("223.inp", "r", stdin); freopen("223.out", "w", stdout);
    Data();
    int kase, kk;
    char line[10], s[2005], temp[10];
    cin >> kase; gets(line);
    for (kk=1; kk<=kase; kk++) {
        gets(s);
        printf("Message #%d\n", kk);
        int len = strlen(s), i = 0;
        while (i<len) {
            if (s[i]==' ') {
                if (s[++i]==' ') {
                    cout << ' '; i++;
                }
                continue;
            }
            sscanf(s+i, "%s", &temp);
            cout << data[temp];
            while (i<len && s[i]!=' ') i++;
        }
        cout << endl;
        if (kk!=kase) cout << endl;
    }
}
