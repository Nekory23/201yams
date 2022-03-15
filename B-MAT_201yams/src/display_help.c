/*
** EPITECH PROJECT, 2021
** display help
** File description:
** 201yams
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "yams.h"

static const char* TAB = "    ";

bool display_error(const char *error)
{
    write(2, error, strlen(error));
    return true;
}

int display_help()
{
    printf("USAGE\n%s", TAB);
    printf("./201yams d1 d2 d3 d4 d5 c\n\n");
    printf("DESCRIPTION\n");
    printf("%sd1 %s value of the first die (0 if not thrown)\n", TAB, TAB);
    printf("%sd2 %s value of the second die (0 if not thrown)\n", TAB, TAB);
    printf("%sd3 %s value of the third die (0 if not thrown)\n", TAB, TAB);
    printf("%sd4 %s value of the fourth die (0 if not thrown)\n", TAB, TAB);
    printf("%sd5 %s value of the fifth die (0 if not thrown)\n", TAB, TAB);
    printf("%sc %s  expected combination\n", TAB, TAB);
    return SUCCESS;
}