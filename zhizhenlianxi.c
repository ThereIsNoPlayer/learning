#include<stdio.h>
int main() {
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int b[4];
    //元素指针
    int *p_e=a;
    // for (int i=0;i<4*4;i++) {
    //     scanf("%d",*p_e+i);
    // }
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            printf("%4d",*(p_e+i*4+j));
        }
        printf("\n");
    }
    //一维数组指针
    int (*p_r)[4];
    // for (int i=0;i<4;i++) {
    //     for (int j=0;j<4;j++) {
    //         scanf("%d",*(p_r+i)+j);
    //     }
    // }
    p_r=a;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            printf("%4d",*(*(p_r+i)+j));
        }
        printf("\n");
    }
    for (int i=0;i<4;i++) {
        p_e=&a[i][0];
        b[i]=*p_e;
        for (int j=0;j<4;j++) {
            if (*(p_e+j)>b[i]) {
                b[i]=*(p_e+j);
            }
        }
    }
    //输出b[i]部分
    int *p_b=b;
    for (int i=0;i<4;i++) {
        printf("b[%d]=%d\n",i,*(p_b+i));
    }
    printf("2513041719赵天珺");
    return 0;
}