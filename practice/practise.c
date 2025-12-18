#include<stdio.h>//2513041719ÕÔÌì¬B
int main() {
    int t;
    for (int i=1000;i<=2100;i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            printf("%d ", i);
            t++;
            if (t%15==0){printf("\n");}
        }
    }
    return 0;
}