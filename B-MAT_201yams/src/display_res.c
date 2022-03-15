/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** display the probabilities
*/

#include <stdio.h>
#include "yams.h"

void display_proba(dice_t *die, double prob)
{
    char *c = NULL;

    switch (die->comb) {
        case 'p' : c = "pair";
            break;
        case 't' : c = "three-of-a-kind";
            break;
        case 'f' : c = "four-of-a-kind";
            break;
        case 'F' : c = "full of";
            break;
        case 's' : c = "straight";
            break;
        case 'y' : c = "yams";
            break;
    }
    if (die->comb != 'F')
        printf("Chances to get a %d %s: %.2f%%\n", die->nbr[0], c, prob);
    else
        printf("Chances to get a %d %s %d: %.2f%%\n", die->nbr[0], c, die->nbr[1], prob);
}