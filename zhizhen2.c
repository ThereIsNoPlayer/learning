#include<stdio.h>
void ptri(int (*tri)[10]) {
    for (int i=0;i<10;i++) {
        for(int j = 0; j <= i; j++) {
            printf("%4d", *(*(tri + i) + j));
        }
        printf("\n");
    }
}
int main() {
    int tri[10][10]={0};
    for (int i=0;i<10;i++) {
        tri[i][0]=1;
        tri[i][i]=1;
        for (int j=0;j<i;j++) {
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
        }
    }
    ptri(tri);
    return 0;
}