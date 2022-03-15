/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** count dice with the expected numbers
*/

#include "yams.h"

int count_good_full(int *dice, int nbr)
{
    int good = 0;

    for (int i = 0; i != 5; i++)
        if (dice[i] == nbr)
            good++;
    return good;
}

int count_good_straight(dice_t *dice)
{
    int good = 0;
    int check = 1;
    int max = 6;

    if (dice->nbr[0] == 6) {
        check = 2;
        max = 7;
    }
    for (; check != max; check++)
        for (int i = 0; i != 5; i++)
            if (check == dice->d[i]) {
                good++;
                break;
            }
    return good;
}