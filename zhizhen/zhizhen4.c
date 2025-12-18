#include<stdio.h>
void count() {
    char str[100];
    int count[10]={0};
    char *s=str;
    int *c=count;
    printf("Enter a string:");
    scanf("%99[^\n]", str);
    while (*s) {
        if (*s>='0' && *s<='9') {
            *(c+(*s-'0'))+=1;
        }
        s++;
    }
    printf("统计结果\n");
    for (int i=0;i<10;i++) {
        printf("数字%c:%d个\n",'0'+i,*(c+i));
    }
}
int main() {
    count();
    return 0;
}