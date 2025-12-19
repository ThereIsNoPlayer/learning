#include<stdio.h>
#define N 5
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
        if(student[i].scoretotal>max_total){
            max_total=student[i].scoretotal;
            max_index=i;
            break;
        }
    }
    printf("%s,scoretotal:%d\n",student[max_index].name,max_total);
    //(4)
    printf("\nSorted by average score:\n");
    struct stu temp;
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1-i;j++){
            if(student[j].average<student[j+1].average){
                temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
                
            }
        }
    }
    printf("NO.\tName\tScore1\tScore2\tScore3\tAverage\n");
    for(int i=0;i<N;i++){
        printf("%d\t%s\t%d\t%d\t%d\t%f\n",student[i].id,student[i].name,student[i].score1,student[i].score2,student[i].score3,student[i].average);
    }
    //(5) 
    printf("\nRanking by average score:\n");
    printf("Rank\tNO.\tName\tAverage\n");
    int rank = 1;
    for(int i=0; i<N; i++){
        if(i == 0){
        printf("%d\t%d\t%s\t%f\n", rank, student[i].id, student[i].name, student[i].average);
    }
        else{
        
            if(student[i].average == student[i-1].average){
            printf("%d\t%d\t%s\t%f\n", rank, student[i].id, student[i].name, student[i].average);
        }
            else{
            
            rank = i + 1;
            printf("%d\t%d\t%s\t%f\n", rank, student[i].id, student[i].name, student[i].average);
        }
    }
}
    return 0;

}