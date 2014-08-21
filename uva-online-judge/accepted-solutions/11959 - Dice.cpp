//*****************
// LAM PHAN VIET **
// UVA 11959 - Dice
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define maxN 10000
string s1;

bool Check(string s2) {
//    cout << s2 << endl;
    string s = "";
    if (s2==s1) return true;
    s = s2[0]; s+=s2[1]; s+=s2[3]; s+=s2[4]; s+=s2[5]; s+=s2[2];
    if (s==s1) return true;
    s = s2[0]; s+=s2[1]; s+=s2[4]; s+=s2[5]; s+=s2[2]; s+=s2[3];
    if (s==s1) return true;
    s = s2[0]; s+=s2[1]; s+=s2[5]; s+=s2[2]; s+=s2[3]; s+=s2[4];
    if (s==s1) return true;
    return false;
}

bool CheckFirst(string s2) {
    int x[10], y[10];
    for (int i=0; i<10; i++)
        x[i] = y[i] = 0;
    for (int i=0; i<6; i++) {
        x[s1[i]-48]++;
        y[s2[i]-48]++;
    }
    for (int i=0; i<10; i++)
        if (x[i]!=y[i]) return false;
    return true;
}

bool Check2(string s2) {
    bool eql;
    string s = "";
    eql = Check(s2);
    if (eql) return true;
    s=s2[1]; s+=s2[0]; s+=s2[5]; s+=s2[4]; s+=s2[3]; s+=s2[2];
    eql = Check(s);
    if (eql) return true;
    
    s = s2[2]; s+=s2[4]; s+=s2[1]; s+=s2[3]; s+=s2[0]; s+=s2[5];
    eql = Check(s);
    if (eql) return true;
    s = s2[4]; s+=s2[2]; s+=s2[5]; s+=s2[0]; s+=s2[3]; s+=s2[1];
    eql = Check(s);
    if (eql) return true;
    
    s = s2[3]; s+=s2[5]; s+=s2[0]; s+=s2[2]; s+=s2[1]; s+=s2[4];
    eql = Check(s);
    if (eql) return true;
    s = s2[5]; s+=s2[3]; s+=s2[4]; s+=s2[1]; s+=s2[2]; s+=s2[0];
    eql = Check(s);
    if (eql) return true;
    return false;
}

main() {
 //   freopen("ii.inp", "r", stdin); freopen("ii.out", "w", stdout);
    int Case; char line[10];
    string s2;
    scanf("%d", &Case);
    while (Case--) {
        cin >> s1 >> s2;
//        cout << s1 << " " << s2 << endl;
        bool eql = false;
        if (CheckFirst(s2)) {
            eql = Check2(s2);
        }
        if (!eql) printf("Not ");
        printf("Equal\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
