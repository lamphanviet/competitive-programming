#include <stdio.h>
#include<iostream>

int rong(char chess[][15]){

    for(int i=2;i<=9;++i)
        for(int j=2;j<=9;++j)
            if( chess[i][j]!='.')
                return 0;
    return 1;
}

int read(char chess[][15])
{   
    int i,j;
    for (i=2;i<=10;++i)                   //Nhap ban co
        fgets(chess[i]+2,20,stdin);
    return rong(chess);
}

/*------------------------------------------*///Kiem tra WHITE
int check_xeo_WHITE(char chess[][15],int x,int y,int plusi,int plusj)
{
    int i=x,j=y;
    while (i>=2 && i<=9 && j>=2 && j<=9) {
          i+=plusi; j+=plusj;
          if (chess[i][j]=='.') continue;
          else if (chess[i][j]=='b' || chess [i][j]=='q') return 1;
          else if (i==x-1 && (j==y+1 || j==y-1) && chess[i][j]=='p') return 1;
          else return 0;
    }
    return 0;
}

int check_thang_WHITE(char chess[][15],int x,int y, int plusi,int plusj)
{
    int i=x,j=y;
    while (i>=2 && i<=9 && j>=2 && j<=9) {
          i+=plusi; j+=plusj;
          if (chess[i][j]=='.') continue;
          else if (chess[i][j]=='r' || chess[i][j]=='q') return 1;
          else return 0;
    }
    return 0;
}

int check_knight_WHITE(char chess[][15],int x,int y)
{
    if (chess[x-2][y-1]=='n' || chess[x-2][y+1]=='n' || chess[x-1][y-2]=='n' || chess[x-1][y+2]=='n' || chess[x+1][y-2]=='n' || chess[x+1][y+2]=='n' || chess[x+2][y-1]=='n' || chess[x+2][y+1]=='n')
       return 1;
    else return 0;
}

/*----------------------------------*///Kiem tra black
int check_xeo_black(char chess[][15],int x,int y,int plusi,int plusj)
{
    int i=x,j=y;
    while (i>=2 && i<=9 && j>=2 && j<=9) {
          i+=plusi; j+=plusj;
          if (chess[i][j]=='.') continue;
          else if (chess[i][j]=='B' || chess [i][j]=='Q') return 1;
          else if (i==x+1 && (j==y+1 || j==y-1) && chess[i][j]=='P') return 1;
          else return 0;
    }
    return 0;
}

int check_thang_black(char chess[][15],int x,int y, int plusi,int plusj)
{
    int i=x,j=y;
    while (i>=2 && i<=9 && j>=2 && j<=9) {
          i+=plusi; j+=plusj;
          if (chess[i][j]=='.') continue;
          else if (chess[i][j]=='R' || chess[i][j]=='Q') return 1;
          else return 0;
    }
    return 0;
}

int check_knight_black(char chess[][15],int x,int y)
{
    if (chess[x-2][y-1]=='N' || chess[x-2][y+1]=='N' || chess[x-1][y-2]=='N' || chess[x-1][y+2]=='N' || chess[x+1][y-2]=='N' || chess[x+1][y+2]=='N' || chess[x+2][y-1]=='N' || chess[x+2][y+1]=='N')
       return 1;
    else return 0;
}

/*-----------------------CHUONG TRINH CHINH-------------------------*/
int main()
{
      char chess[15][15];
      memset(chess,0,sizeof(chess));
      int con,i,j,game=1,k1=0,k2,x1,y1,x2,y2;
      int plusi,plusj;
      int isEmpty = read(chess);
      
      while (!isEmpty)
      {
            con=0;
            for (i=2;i<=9;i++)                      //Tim vi tri cua black king (x1,y1) va WHITE KING (x2,y2)
                for (j=2;j<=9;j++) {
                    if (chess[i][j]=='k') {
                       x1=i; y1=j;
                       con++;
                    }
                    if (chess[i][j]=='K') {
                       x2=i; y2=j;
                       con++;
                    }
                    if (con==2) break;
                }
                
            if (check_xeo_WHITE(chess,x2,y2,-1,-1)) k2=1;
            else if (check_xeo_WHITE(chess,x2,y2,-1,1)) k2=1;
            else if (check_xeo_WHITE(chess,x2,y2,1,-1)) k2=1;
            else if (check_xeo_WHITE(chess,x2,y2,1,1)) k2=1;
            else if (check_thang_WHITE(chess,x2,y2,-1,0)) k2=1;
            else if (check_thang_WHITE(chess,x2,y2,1,0)) k2=1;
            else if (check_thang_WHITE(chess,x2,y2,0,-1)) k2=1;
            else if (check_thang_WHITE(chess,x2,y2,0,1)) k2=1;
            else if (check_knight_WHITE(chess,x2,y2)) k2=1;
            else k2=0;
            
            if (k2==1) printf("Game #%d: white king is in check.\n",game);
            else if (check_xeo_black(chess,x1,y1,-1,-1)) k1=1;
            else if (check_xeo_black(chess,x1,y1,-1,1)) k1=1;
            else if (check_xeo_black(chess,x1,y1,1,-1)) k1=1;
            else if (check_xeo_black(chess,x1,y1,1,1)) k1=1;
            else if (check_thang_black(chess,x1,y1,-1,0)) k1=1;
            else if (check_thang_black(chess,x1,y1,1,0)) k1=1;
            else if (check_thang_black(chess,x1,y1,0,-1)) k1=1;
            else if (check_thang_black(chess,x1,y1,0,1)) k1=1;
            else if (check_knight_black(chess,x1,y1)) k1=1;
            else k1=0;
            if (k1==0 && k2==0) printf("Game #%d: no king is in check.\n",game);
            else if (k1==1 && k2==0) printf("Game #%d: black king is in check.\n",game);
            game++;
            
            isEmpty = read(chess);
      }
}
            
