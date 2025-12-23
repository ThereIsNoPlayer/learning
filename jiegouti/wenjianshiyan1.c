#include<stdio.h>//2513041719赵天珺
#define N 100
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
    struct stu student[5];
    for(int i=0;i<5;i++){
        input(&student[i]);
        average(&student[i]);
    }fp=fopen("studfile.dat","w");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    fprintf(fp,"NO.\tName\tScore1\tScore2\tScore3\tAverage\n");
    for(int i=0;i<5;i++){
        fprintf(fp,"%d\t%s\t%d\t%d\t%d\t%f\n",student[i].num,student[i].name,student[i].score1,student[i].score2,student[i].score3,student[i].average);
    }
    fclose(fp);
    printf("Read\n");
    char str[N];
    fp=fopen("studfile.dat","r");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }
    while(fgets(str,N,fp)!=NULL){
        printf("%s",str);
    }
    fclose(fp);
    return 0;
}