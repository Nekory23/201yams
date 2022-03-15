/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** error handling
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "yams.h"

static bool check_numbers(char **args, int nbr)
{
    for (int i = 1; i != nbr; i++) {
        if (strlen(args[i]) != 1)
            return true;
        for (int j = 0; args[i][j] != '\0'; j++) {
            if (args[i][j] >= '0' && args[i][j] <= '6')
                continue;
            return true;
        }
    }
    return false;
}

static bool check_one(char *comb, int i)
{
    int len = strlen(comb);
    int nbr = 0;

    for (size_t i = 0; i != strlen(comb); i++)
        if (comb[i] >= '0' && comb[i] <= '6')
            nbr++;
    if (nbr != 1)
        return true;
    if (i == 4 || i == 5) {
        if (i == 4) {
            if (comb[len - 1] >= '5' && comb[len - 1] <= '6')
                return false;
            return true;
        }
        if (i == 5) {
            if (comb[len - 1] >= '4' && comb[len - 1] <= '6')
                return false;
            return true;
        }
    }
    if (comb[len - 1] >= '1' && comb[len - 1] <= '6')
        return false;
    return true;
}

static bool check_two(char *comb)
{
    int len = strlen(comb);

    if (comb[len - 3] >= '1' && comb[len - 3] <= '6'&& comb[len - 2] == '_')
        if (comb[len - 1] >= '1' && comb[len - 1] <= '6')
            if (comb[len - 1] != comb[len - 3])
                return false;
    return true;
}

static bool check_combination(char *comb)
{
    char *cmp[7] = {"pair_", "three_", "four_", "full_", "straight_", "little_straight_", "yams_"};

    for (int i = 0; i != 7; i++)
        if (strncmp(cmp[i], comb, strlen(cmp[i])) == TRUE) {
            if (i == 3)
                return (check_two(comb));
            return (check_one(comb, i));
        }
    return true;
}

bool error_handling(int nbr, char **args)
{
    if (nbr != 7)
        return (display_error(ERR_NBR_ARGS));
    nbr -= 1;
    if (check_numbers(args, nbr))
        return (display_error(ERR_NUMBERS));
    if (check_combination(args[nbr]))
        return (display_error(ERR_COMB));
    return false;
}