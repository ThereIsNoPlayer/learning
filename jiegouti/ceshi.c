#include <stdio.h>
int main( ) {
    FILE *fp;
    int i,a[4]= {1,2,3,4},b;
    fp=fopen("data.dat","wb");
    for(i=0; i<4; i++)
        fwrite(&a[i],sizeof(int),1,fp);
    fclose(fp);
    fp=fopen("data.dat","rb");
    fseek(fp,-2*sizeof(int),SEEK_END);
    fread(&b,sizeof(int),1,fp);
    fclose(fp);
    printf("%d\n",b) ;
    return 0;
}