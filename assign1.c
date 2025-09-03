#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate) {
    printf("Date initialization...\n");

    ptrDate->day = 0;
    ptrDate->month = 0;
    ptrDate->year = 0;

    printf("Initialized Date: %d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate) {
    printf("After input:\n");
    printf("Date: %d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate) {
    printf("Enter the day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter the month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter the year: ");
    scanf("%d", &ptrDate->year);
}

int main() {
    struct Date date;
    int x;

    do {
        printf("\nMenu-driven selection:\n");
        printf("1: Initialize date\n");
        printf("2: Print date\n");
        printf("3: Accept date from console\n");
        printf("0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                initDate(&date);
                break;
            case 2:
                printDateOnConsole(&date);
                break;
            case 3:
                acceptDateFromConsole(&date);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (x != 0);

    return 0;
}