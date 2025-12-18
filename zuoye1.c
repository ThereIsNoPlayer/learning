#include<stdio.h>
#include<string.h>
int main() {
    char str[10][100];
    int count;
    printf("数组个数:");
    scanf("%d",&count);
    getchar();
    printf("请输入%d个字符串",count);
    for (int i=0;i<count;i++) {
        char *p=str[i];
        fgets(p,100,stdin);
        while (*p != '\n' && *p != '\0') {
            p++;
        }
        *p = '\0';
    }
    char *min=str[0];
    for (int i=1;i<count;i++) {
        char *c=str[i];
        if (strlen(c)<strlen(min)) {
            min=c;
        }
    }
    printf("min:%s",min);
    return 0;
}