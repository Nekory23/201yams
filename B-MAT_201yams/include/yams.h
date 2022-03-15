/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** include
*/

#ifndef _YAMS_
#define _YAMS_

#include <math.h>
#include "stdbool.h"

// structure
typedef struct dice_s {
    int d[5];
    char comb;
    int nbr[2];
} dice_t;

// prototypes
// error handling
bool error_handling(int, char **);
bool display_error(const char *);
int display_help();

// yams
void yams(char **);
dice_t *fill_struct(char **);

// count nbr of good dice
int count_good_straight(dice_t *);
int count_good_full(int *, int);

// compute
double binomial(double, double);
double combination(double, double);
double factorial(double);

// display res
void display_proba(dice_t *, double);

// constants
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 0;
static const int FALSE = 1;

// error messages
static const char ERR_NBR_ARGS[] = "The number of args is invalid (try again with -h)\n";
static const char ERR_NUMBERS[] = "The value of the die are incorrect (try again with -h)\n";
static const char ERR_COMB[] = "The combination is incorrect (try again with -h)\n";

#endif