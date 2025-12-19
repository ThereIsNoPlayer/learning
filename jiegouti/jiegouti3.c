#include<stdio.h>

void partition(unsigned long num){
    unsigned short pt1=(unsigned short)(num>>16);
    unsigned short pt2=(unsigned short)(num&0xffff);
    printf("The higher 16 bits: %hx (0x%04X)\n",pt1,pt1);
    printf("The lower 16 bits: %hx (0x%04X)\n",pt2,pt2);
}
int main(){
    unsigned long num;
    printf("Input an unsigned long integer:\n");
    scanf("%lx",&num);
    printf("The original number: %lx (0x%08lX)\n",num,num);
    partition(num);
    return 0;
}