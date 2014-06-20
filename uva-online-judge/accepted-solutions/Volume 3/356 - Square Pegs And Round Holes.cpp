#include <stdio.h>
#include <math.h>

int n,seg,ins;
double rad;

double Distance(int i, int j) {
    return ((i-n)*(i-n)+(j-n)*(j-n));
}

void Count() {
    seg=ins=0;
    rad=(n-0.5)*(n-0.5);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
            if (Distance(i,j)<rad) ins++;
            else if (Distance(i+1,j+1)<=rad) seg++;
        }
    
    seg*=4; ins*=4;
}

main() {
    bool line=false;
    while (scanf("%d",&n)!=EOF) {
        if (line) printf("\n");
        Count();
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,seg);
        printf("There are %d cells completely contained in the circle.\n",ins);
        line=true;
    }
}
