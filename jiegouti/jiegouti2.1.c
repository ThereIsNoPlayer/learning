#include<stdio.h>//2513041719赵天珺
#define N 3
#include<string.h>
struct stu{
    int id;
    char name[20];
    int score1;
    int score2;
    int score3;
    float scoretotal;
    float average;
}student;
int main(){
    struct stu student[N];
    for(int i=0;i<N;i++){
        printf("Input NO.,Name,Score1,Score2,Score3 of student %d:\n",i+1);
        scanf("%d%s%d%d%d",&student[i].id,student[i].name,&student[i].score1,&student[i].score2,&student[i].score3);
        student[i].scoretotal=student[i].score1+student[i].score2+student[i].score3;
        student[i].average=student[i].scoretotal/3.0;
    }
    printf("NO.\tName\tScore1\tScore2\tScore3\tAverage\n");
    for(int i=0;i<N;i++){
        printf("%d\t%s\t%d\t%d\t%d\t%f\n",student[i].id,student[i].name,student[i].score1,student[i].score2,student[i].score3,student[i].average);
    }
    float average_sum=0;
    for(int i=0;i<N;i++){
        average_sum+=student[i].average;
    }
    printf("Average of all students: %f\n",average_sum/N);
    printf("The highest score is:");
    int max_total=0;
    int max_index=0;
    for(int i=0;i<N;i++){
        if(student[i].scoretotal>=max_total){
            max_total=student[i].scoretotal;
            max_index=i;
            break;
        }
    }
    printf("%s,scoretotal:%d",student[max_index].name,max_total);
    return 0;

}