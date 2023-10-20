#include <stdio.h>
#include <time.h>

int main() {
    int year, month;

    // Input the year and month from the user
    printf("Enter year (e.g., 2023): ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Check for valid input
    if (year < 0 || month < 1 || month > 12) {
        printf("Invalid input. Please enter a valid year and month.\n");
        return 1;
    }

    // Initialize a struct tm with the specified year and month
    struct tm date = {
        .tm_year = year - 1900,  // Years since 1900
        .tm_mon = month - 1,    // Months (0-11)
        .tm_mday = 1            // Day of the month (1-31)
    };

    // Normalize the date (this calculates other fields in the struct tm)
    mktime(&date);

    // Print the calendar header
    printf("Calendar for %d-%02d:\n", year, month);

    // Print the days of the week
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Calculate the day of the week for the first day of the month
    int dayOfWeek = date.tm_wday;

    // Print leading spaces to align the first day
    for (int i = 0; i < dayOfWeek; i++) {
        printf("    ");
    }

    // Print the days of the month
    while (date.tm_mon == month - 1) {
        printf("%3d ", date.tm_mday);
        if (dayOfWeek == 6) {  // Saturday
            printf("\n");
        }
        date.tm_mday++;
        dayOfWeek = (dayOfWeek + 1) % 7;
        mktime(&date);
    }

    printf("\n");

    return 0;
}