#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void clrscr()
{
    system("@cls||clear");
}


char pdigits[11][26] = {
    " ### #   ##   ##   # ### ",
    "  #   ##    #    #    #  ",
    "#####    #######    #####",
    "#####    #  ###    ######",
    "#    # #  #####  #    #  ",
    "######    #####    ######",
    "######    ######   ######",
    "#####   #    #   #    #  ",
    "######   #######   ######",
    "######   ######    ######",
    "       #         #       "
};

void format_time(char *output){
    time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    sprintf(output, "[%d %d %d %d:%d:%d]", timeinfo->tm_mday,
            timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

typedef struct Digits {
    char h1;
    char h2;
    char m1;
    char m2;
    char s1;
    char s2;
} Digits;

Digits convert_time(struct tm *timeinfo) {
    Digits digits;
    digits.h1 = timeinfo->tm_hour / 10;
    digits.h2 = timeinfo->tm_hour % 10;
    digits.m1 = timeinfo->tm_min / 10;
    digits.m2 = timeinfo->tm_min % 10;
    digits.s1 = timeinfo->tm_sec / 10;
    digits.s2 = timeinfo->tm_sec % 10;
    return digits;
}

int main(void)
{
    while (1) {
        time_t rawtime;
        struct tm * timeinfo;
        
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        clrscr();
        Digits digits = convert_time(timeinfo);
        for (int i = 0; i < 5; i++) {
            printf("%.5s ", pdigits[digits.h1] + 5 * i);
            printf("%.5s", pdigits[digits.h2] + 5 * i);
            printf("%.5s", pdigits[10] + 5 * i);
            printf("%.5s ", pdigits[digits.m1] + 5 * i);
            printf("%.5s", pdigits[digits.m2] + 5 * i);
            printf("%.5s", pdigits[10] + 5 * i);
            printf("%.5s ", pdigits[digits.s1] + 5 * i);
            printf("%.5s\n", pdigits[digits.s2] + 5 * i);
        }
        // printf("%d %d %d %d %d %d\n", digits.h1, digits.h2, digits.m1, digits.m2, digits.s1, digits.s2);
        sleep(1);
    }

    return 0;
}