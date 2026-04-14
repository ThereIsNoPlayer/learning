#include<stdio.h>
int main(){
    FILE *fp;
    fp=fopen("test.txt","w");
    char str[100];
    if(fp==NULL){
        printf("error");
        return 1;
    }
    fprintf(fp,"hello");
    fclose(fp);
    if((fp=fopen("test.txt","r"))==NULL){
        printf("error");
        return 1;
    }
    fgets(str,100,fp);
    printf("%s",str);
    fclose(fp);
    return 0;
}