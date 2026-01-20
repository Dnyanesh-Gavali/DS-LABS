#include<stdio.h>
#include <string.h>
#include <strings.h>


int first_day(int year) {
    int day =( ((year-1) * 365) + (year-1)/4 - (year-1)/100 + (year-1)/400 + 1 )% 7;
    return day;
}
int main() {

    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    char month[4];
    printf("\nEnter the first three char of month: ");
    scanf("%3s", month);

    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    char weekdays[7][4] = {"Sun", "Mon", "Tue", "Wed", "thu", "Fri", "Sat"};

    if ((year % 4==0 && year %100 !=0) || year % 400 == 0) {
        month_days[1] = 29;
    }

    int start_day, total_days=0, month_index;
    for (int i= 0; i<12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            month_index = i;
            break;
        }
        total_days += month_days[i];
    }

    start_day = (first_day(year) + total_days) % 7;

    printf("\n------------ %s %d ------------\n", month, year);

    for (int i = 0; i < 7; i++) {
        printf("%s ", weekdays[i]);
    }
    printf("\n");

    int column = start_day;
    for (int i = 0; i < column; i++) {
        printf("    ");
    }

    for (int day = 1; day <= month_days[month_index]; day++) {
        printf("%3d ", day);
        column++;

        if (column == 7) {
            printf("\n");
            column = 0;
        }
    }

    printf("\n");

}