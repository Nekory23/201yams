/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** main
*/

#include <string.h>
#include "yams.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == TRUE)
        return display_help();
    if (error_handling(ac, av))
        return (ERROR);
    yams(av);
    return (SUCCESS);
}