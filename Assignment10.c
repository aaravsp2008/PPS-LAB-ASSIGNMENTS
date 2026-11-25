
#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

int main()
{
    int year, month, day;
    int days, startDay;
    int i, j;

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    scanf("%d", &year);

    if (isLeapYear(year))
        monthDays[1] = 29;

    startDay = 1;

    for (i = 1; i < year; i++)
    {
        startDay += isLeapYear(i) ? 366 : 365;
    }

    startDay %= 7;

    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (j = 0; j < startDay; j++)
            printf("    ");

        days = monthDays[month];

        for (day = 1; day <= days; day++)
        {
            printf("%3d ", day);

            if ((startDay + day) % 7 == 0)
                printf("\n");
        }

        startDay = (startDay + days) % 7;
    }

    printf("\n");

    return 0;
}

