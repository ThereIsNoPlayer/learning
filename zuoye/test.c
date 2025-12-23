#include <stdio.h>

/*请在这里编写你的代码*/
int sum(int m, int n){
    int tt=0;
    for(int j=m;j<=n;j++){
        tt+=j;
    }
    return tt;

}

int main()
{    
    int m, n;
    scanf("%d %d", &m, &n);
    printf("sum = %d", sum(m, n));
    return 0;
}