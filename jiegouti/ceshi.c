#include<stdio.h>
int main(){
    FILE *fp;
    fp=fopen("test.txt","w");
    char str[100];
    scanf("%[^\n]",str);
    fputs(str,fp);
    fclose(fp);

    fopen("test.txt","r");
    fgets(str,100,fp);
    printf("Read from file: %s\n",str);
    fclose(fp);
    return 0;
}