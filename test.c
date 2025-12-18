
#include <stdio.h>

// int change(int *a,int *b) {
//     int t=*a;
//     *a=*b;
//     *b=t;
// }
// int main() {
//     int x=0,y=1;
//     printf("a=%d b=%d\n",x,y);
//     change(&x,&y);
//     printf("a=%d b=%d\n",x,y);
//
//
// }


int main() {
    char a[6];
    //a[i]==*(a+i)
    for (int i=0;i<6;i++)scanf("%d",&a[0]);
    fgets(a,6,stdin);
    printf("%s",a);
}