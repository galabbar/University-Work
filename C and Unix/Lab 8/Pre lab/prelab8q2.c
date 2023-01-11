//Name: Ghazi Najeeb Al-Abbar
//id: 2181148914
//prelab8q2.c

#include <stdio.h>

typedef struct work_hours{

    int hours;
    int minutes;

}WorkHours;

int main(){

    int TotalHours = 0, TotalMinutes = 0;
    double TotalPay = 0;
    WorkHours Friday, Saturday;

    printf("Enter the number of hours and minutes worked on Friday: ");
    scanf("%d %d", &Friday.hours, &Friday.minutes);

    printf("Enter the number of hours and minutes worked on Saturday: ");
    scanf("%d %d", &Saturday.hours, &Saturday.minutes);

    TotalHours = Friday.hours + Saturday.hours + (Friday.minutes + Saturday.minutes)/60;
    TotalMinutes = (Friday.minutes + Saturday.minutes)%60;
    TotalPay = 8 * TotalHours;
    puts("\n");

    printf("On Friday, the student worked for %d Hour(s) and %d Minute(s)\n", Friday.hours, Friday.minutes);
    printf("On Saturday, the student worked for %d Hour(s) and %d Minute(s)\n", Saturday.hours, Saturday.minutes);

    printf("The student has worked a total of %d Hour(s) and %d Minute(s)\n", TotalHours, TotalMinutes);
    printf("The total amount to be paid is %lf KD\n", TotalPay);

    return 0;
}
