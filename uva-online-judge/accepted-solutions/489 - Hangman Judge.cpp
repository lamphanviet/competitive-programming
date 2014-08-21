// Problem 489 - Hangman Judge
#include <iostream>
#include <string.h>

using namespace std;

main() {
    int round,count,i,rs,wlen,glen,j;
    char word[100],guess[100];
    bool ans['z'+10];
    
    while ((cin >> round) && round>=0) {
        getchar();
        gets(word); gets(guess);
        wlen = strlen(word);
        glen = strlen(guess);
        memset(ans,false,'z'+5);
        for (i=0;i<wlen;i++)
            ans[word[i]]=true;
        count = 0;
        rs = 2;
        for (i=0;i<glen;i++) {
            j = 0;
            while (j<wlen && guess[i]!=word[j]) j++;
            if (j>=wlen) count++;
            else if (ans[guess[i]]) {
                ans[guess[i]]=false;
                j = 0;
                while (j<wlen && !ans[word[j]]) j++;
                if (j>=wlen) {
                    rs = 1;
                    break;
                }
            }
            if (count==7) {
                rs = 3;
                break;
            }
        }
        
        cout << "Round " << round << endl;
        if (rs==1) cout << "You win.";
        else if (rs==2) cout << "You chickened out.";
        else cout << "You lose.";
        cout << endl;
    }
}
