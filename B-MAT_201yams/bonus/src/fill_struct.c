/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** fill the structure
*/

#include <stdlib.h>
#include <string.h>
#include "yams.h"

static void get_comb(dice_t *die, char *arg)
{
    char *cmp[7] = {"pair_", "three_", "four_", "full_", "straight_", "little_straight_", "yams_"};

    for (int i = 0; i != 7; i++) {
        if (strncmp(cmp[i], arg, strlen(cmp[i])) == TRUE) {
            if (i == 3) {
                die->comb = 'F';
                die->nbr[0] = arg[strlen(arg) - 3] - 48;
                die->nbr[1] = arg[strlen(arg) - 1] - 48;
                return;
            }
            die->comb = cmp[i][0];
            die->nbr[0] = arg[strlen(arg) - 1] - 48;
            die->nbr[1] = 0;
            return;
        }
    }
}

dice_t *fill_struct(char **args)
{
    dice_t *die = malloc(sizeof(dice_t));

    for (int i = 1; i != 6; i++)
        die->d[i-1] = atoi(args[i]);
    get_comb(die, args[6]);
    return die;
}