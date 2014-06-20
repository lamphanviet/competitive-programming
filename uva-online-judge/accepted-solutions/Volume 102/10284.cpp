#include <iostream>

using namespace std;

char a[11][11],s[100];

void Process() {
    int n,i,j,k,row,col;
    n = strlen(s);
    k = 1;
    row = 1; col=0;
    for (i=0;i<n;i++) {
        if (s[i]=='/') {
            row++; col=0; continue;
        }
        if (s[i]<='8' && s[i]>='1') {
            col += s[i]-48; continue;
        }
        else {
            a[row][++col] = s[i];
        }
    }
}

void King(int x, int y) {
    int i,j;
    for (i=x-1;i<=x+1;i++)
        for (j=y-1;j<=y+1;j++)
            if (a[i][j]=='0') a[i][j]='1';
}

void RQB(int k, int x, int y) {
    int i,j;
    if (k!=3) {
        i=x+1;
        while (a[i][y]=='0' || a[i][y]=='1') { a[i][y]='1'; i++; }
        i=x-1;
        while (a[i][y]=='0' || a[i][y]=='1') { a[i][y]='1'; i--; }
        j=y+1;
        while (a[x][j]=='0' || a[x][j]=='1') { a[x][j]='1'; j++; }
        j=y-1;
        while (a[x][j]=='0' || a[x][j]=='1') { a[x][j]='1'; j--; }
    }
    if (k!=1) {
        i=x+1; j=y+1;
        while (a[i][j]=='0' || a[i][j]=='1') { a[i][j]='1'; i++; j++; }
        i=x-1; j=y-1;
        while (a[i][j]=='0' || a[i][j]=='1') { a[i][j]='1'; i--; j--; }
        i=x+1; j=y-1;
        while (a[i][j]=='0' || a[i][j]=='1') { a[i][j]='1'; i++; j--; }
        i=x-1; j=y+1;
        while (a[i][j]=='0' || a[i][j]=='1') { a[i][j]='1'; i--; j++; }
    }
}

void Knight(int x, int y) {
    if (x>=2) {
        if (a[x-2][y-1]=='0') a[x-2][y-1]='1';
        if (a[x-2][y+1]=='0') a[x-2][y+1]='1';
    }
    if (y>=2) {
        if (a[x-1][y-2]=='0') a[x-1][y-2]='1';
        if (a[x+1][y-2]=='0') a[x+1][y-2]='1';
    }
    if (a[x+2][y-1]=='0') a[x+2][y-1]='1';
    if (a[x+2][y+1]=='0') a[x+2][y+1]='1';
    if (a[x+1][y+2]=='0') a[x+1][y+2]='1';
    if (a[x-1][y+2]=='0') a[x-1][y+2]='1';
}

void WhilePawn(int x, int y) {
    if (a[x-1][y+1]=='0') a[x-1][y+1]='1';
    if (a[x-1][y-1]=='0') a[x-1][y-1]='1';
}

void BlackPawn(int x, int y) {
    if (a[x+1][y+1]=='0') a[x+1][y+1]='1';
    if (a[x+1][y-1]=='0') a[x+1][y-1]='1';
}

int Run() {
    int i,j;
    char temp;
    for (i=1;i<=8;i++)
        for (j=1;j<=8;j++)
            if (a[i][j]!='0' && a[i][j]!='1') {
                temp = a[i][j];
                if (temp=='K' || temp=='k') King(i,j);
                else if (temp=='R' || temp=='r') RQB(1,i,j);
                else if (temp=='Q' || temp=='q') RQB(2,i,j);
                else if (temp=='B' || temp=='b') RQB(3,i,j);
                else if (temp=='N' || temp=='n') Knight(i,j);
                else if (temp=='P') WhilePawn(i,j);
                else if (temp=='p') BlackPawn(i,j);
            }
    
    int count = 0;
    for (i=1;i<=8;i++)
        for (j=1;j<=8;j++)
            if (a[i][j]=='0') count++;
            
    return count;
}

main() {
//    freopen("284.inp","r",stdin);
 //   freopen("284.out","w",stdout);
    
    int i,j,k;
    while (gets(s)) {
        for (i=0;i<=9;i++) {
            a[0][i]=a[i][0]=a[9][i]=a[i][9]='2';
        }
        for (i=1;i<=8;i++)
            for (j=1;j<=8;j++)
                a[i][j] = '0';
        Process();
        cout << Run() << endl;
/*        for (i=0;i<=9;i++) {
            for (j=0;j<=9;j++)
                cout << a[i][j] << " ";
            cout << endl; 
        } */
    }
}
