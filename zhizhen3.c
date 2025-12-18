#include<stdio.h>
void dtb(int num) {
    if (num==0) {
        printf("0");
    }
    int b[32];
    int *start=b;
    int *end=b;
    while (num>0) {
        *end=num%2;
        num/=2;
        end++;
    }
    if (start==end) {
        printf("0");
        return;
    }
    printf("¶þ½øÖÆ:");
    end--;
    while (end>=start) {
        printf("%d",*end);
        end--;
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d",&n);
    if (n<0) {
        return 1;
    }
    dtb(n);
    return 0;
}