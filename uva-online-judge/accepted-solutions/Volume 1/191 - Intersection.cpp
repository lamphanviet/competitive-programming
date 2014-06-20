/*****************/
/* LAM PHAN VIET */
/* UVa: 191 - Intersection
/* Time limit: 3.000s
/********************************/
#include <stdio.h>
#include <math.h>

int ux,uy,vx,vy;
int ax,ay,bx,by,cx,cy,dx,dy;

int max(int a, int b) {
    if (a>b) return a;
    return b;
}

int min(int a, int b) {
    if (a<b) return a;
    return b;
}

long Side(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y1-y2)*(x2-x3)-(x1-x2)*(y2-y3);
}

bool Check_line(int x1, int y1, int x2, int y2) {
    long t1=Side(ux,uy,x1,y1,x2,y2)*Side(vx,vy,x1,y1,x2,y2);
    long t2=Side(x1,y1,ux,uy,vx,vy)*Side(x2,y2,ux,uy,vx,vy);
    if (t1<0 && t2<=0) return true;
    if (t1==0 && t2==0) {
        if ((min(ux,vx)<=x1 && x1<=max(ux,vx))&&(min(uy,vy)<=y1 && y1<=max(uy,vy))) return true;
        if ((min(ux,vx)<=x2 && x2<=max(ux,vx))&&(min(uy,vy)<=y2 && y2<=max(uy,vy))) return true;
    }
    return false;
}

bool Check() {
    if (min(ax,cx)<=ux && ux<=max(ax,cx) && min(cy,ay)<=uy && uy<=max(ay,cy)) return true;
    if (min(ax,cx)<=vx && vx<=max(ax,cx) && min(cy,ay)<=vy && vy<=max(ay,cy)) return true;
    
    if (Check_line(ax,ay,bx,by)) return true;
    if (Check_line(bx,by,cx,cy)) return true;
    if (Check_line(cx,cy,dx,dy)) return true;
    if (Check_line(dx,dy,ax,ay)) return true;
    return false;
}

int main() {
 //   freopen("191inp.txt","r",stdin);
 //   freopen("191out.txt","w",stdout);
    int kase;
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d %d %d %d",&ux,&uy,&vx,&vy);
        scanf("%d %d %d %d",&ax,&ay,&cx,&cy);
        bx=cx; by=ay; dx=ax; dy=cy;
        if (Check()) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
