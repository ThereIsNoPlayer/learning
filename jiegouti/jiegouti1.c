#include<stdio.h>
struct days {
    int year;
    int month;
    int day;
}cdays;
int leapyears(int y) {
    return((y%4==0&&y%100!=0)||y%400==0);
}
int countdays(int y,int m,int d) {
    int days=0;
    int i;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapyears(y)) {
        monthDays[1]=29;
    }
    for (i=1;i<m;i++) {
        days+=monthDays[i];
    }
    days+=d;
    return days;
}
int main() {
    printf("y,m,d\n");
    scanf("%d%d%d",&cdays.year,&cdays.month,&cdays.day);
    if (leapyears(cdays.year)) {
        printf("%d is a leap year\n",cdays.year);
    }else {
        printf("%d is not a leap year\n",cdays.year);
    }
    printf("%d/%d/%d is the %dth day of the year",cdays.year,cdays.month,cdays.day,countdays(cdays.year,cdays.month,cdays.day));
}