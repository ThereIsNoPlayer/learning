#include<stdio.h>
#define N 100
#define M 5
struct stu{
    int num;
    char name[20];
    int score1;
    int score2;
    int score3;
    float scoretotal;
    float average;
}student;
void input(struct stu *stu){
    scanf("%d%19s%d%d%d",&stu->num,stu->name,&stu->score1,&stu->score2,&stu->score3);
}
float average(struct stu *stu){
    stu->scoretotal=stu->score1+stu->score2+stu->score3;
    return stu->average=stu->scoretotal/3.0;
}
int main(){
    FILE *fp;
    struct stu student[M];
    for(int i=0;i<M;i++){
        input(&student[i]);
        average(&student[i]);
    }fp=fopen("studfile.dat","w");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    fprintf(fp,"NO.\tName\tScore1\tScore2\tScore3\tAverage\n");
    for(int i=0;i<M;i++){
        fprintf(fp,"%d\t%s\t%d\t%d\t%d\t%f\n",student[i].num,student[i].name,student[i].score1,student[i].score2,student[i].score3,student[i].average);
    }
    fclose(fp);
    fp=fopen("studfile.dat","r");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    char header[N];
    fgets(header, N, fp);
    struct stu sorted[M];
    for(int i=0;i<M;i++){
        fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%f\n",&sorted[i].num,sorted[i].name,&sorted[i].score1,&sorted[i].score2,&sorted[i].score3,&sorted[i].average);
    }
    fclose(fp);

    struct stu temp;
    for(int i=0;i<M-1;i++){
        for(int j=0;j<M-1-i;j++){
            if(sorted[j].average<sorted[j+1].average){
                temp=sorted[j];
                sorted[j]=sorted[j+1];
                sorted[j+1]=temp;
                
            }
        }
    }
    FILE *fp2;
    fp2=fopen("stuscore.dat","w");
    if(fp2==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    fprintf(fp2,"%s",header);
    for(int i=0;i<M;i++){
        fprintf(fp2,"%d\t%s\t%d\t%d\t%d\t%f\n",sorted[i].num,sorted[i].name,sorted[i].score1,sorted[i].score2,sorted[i].score3,sorted[i].average);
    }
    fclose(fp2);
    printf("read from stuscore.dat:\n");
    fp2=fopen("stuscore.dat","r");
    if(fp2==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    while(fgets(header, N, fp2) != NULL) {
        printf("%s", header);    
    }
    fclose(fp2);
    return 0;
}