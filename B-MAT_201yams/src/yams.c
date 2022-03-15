/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** yams
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "yams.h"

void pair_three_four_yams(dice_t *dice, int nbr)
{
    double good = 0;
    double prob = 0;

    for (int i = 0; i != 5; i++)
        if (dice->d[i] == dice->nbr[0])
            good++;
    if (good >= nbr)
        return (display_proba(dice, 100));
    for (double i = nbr - good; i != (5 - good + 1); i++)
        prob += binomial(i, 5 - good);
    display_proba(dice, prob * 100);
}

void full(dice_t *dice)
{
    int goodt = count_good_full(dice->d, dice->nbr[0]);
    int goodp = count_good_full(dice->d, dice->nbr[1]);
    double three = 0;
    double pair = 0;
    double prob = 0;

    if (goodt == 3 && goodp == 2)
        return (display_proba(dice, 100));
    if (goodt > 3)
        goodt = 3;
    if (goodp > 2)
        goodp = 2;
    three = combination(3 - goodt, 5 - goodt - goodp);
    pair = combination(2 - goodp, 2 - goodp);
    prob = three * pair / pow(6, 5 - goodp - goodt);
    display_proba(dice, prob * 100);
}

void straight(dice_t *dice)
{
    int good = count_good_straight(dice);
    double prob = 0;

    if (good == 5)
        return (display_proba(dice, 100));
    prob = factorial(5 - good) / pow(6, (5 - good));
    display_proba(dice, prob * 100);
}

void yams(char **args)
{
    dice_t *dice = fill_struct(args);

    switch (dice->comb) {
        case 'p' : pair_three_four_yams(dice, 2);
            break;
        case 't' : pair_three_four_yams(dice, 3);
            break;
        case 'f' : pair_three_four_yams(dice, 4);
            break;
        case 'F' : full(dice);
            break;
        case 's' : straight(dice);
            break;
        case 'y' : pair_three_four_yams(dice, 5);
            break;
    }
    free(dice);
}