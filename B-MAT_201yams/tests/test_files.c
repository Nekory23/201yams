/*
** EPITECH PROJECT, 2021
** unit_test
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "yams.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_res, display, .init=redirect_all_stdout)
{
    dice_t *dice;
    double res = 0.01;
    char *av[7];

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "2\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "full_2_1\0";
    dice = fill_struct(av);
    cr_assert_eq(dice->d[0], 5);
    cr_assert_eq(dice->d[1], 2);
    cr_assert_eq(dice->d[2], 1);
    cr_assert_eq(dice->d[3], 1);
    cr_assert_eq(dice->d[4], 1);
    cr_assert_eq(dice->comb, 'F');
    cr_assert_eq(dice->nbr[0], 2);
    cr_assert_eq(dice->nbr[1], 1);
    display_proba(dice, res);
    cr_assert_stdout_eq_str("Chances to get a 2 full of 1: 0.01%\n", "");
}

Test(error_few_arg, exit_code, .init=redirect_all_stdout)
{
    int ac = 1;
    char **av;

    error_handling(ac, av);
    cr_assert_stderr_eq_str("The number of args is invalid (try again with -h)\n", "");
}

Test(error_many_arg, exit_code, .init=redirect_all_stdout)
{
    int ac = 10;
    char **av;

    error_handling(ac, av);
    cr_assert_stderr_eq_str("The number of args is invalid (try again with -h)\n", "");
}

Test(error_nb_arg, exit_code, .init=redirect_all_stdout)
{
    int ac = 7;
    char *av[7];

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "9\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "pair_4\0";
    error_handling(ac, av);
    cr_assert_stderr_eq_str("The value of the die are incorrect (try again with -h)\n","");
}

Test(error_comb_arg, exit_code, .init=redirect_all_stdout)
{
    int ac = 7;
    char *av[7];

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "2\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "pair_8\0";
    error_handling(ac, av);
    cr_assert_stderr_eq_str("The combination is incorrect (try again with -h)\n","");
}

Test(test_full_arg, full_arg, .init=redirect_all_stdout)
{
    int ac = 7;
    char *av[7];

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "2\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "full_2_2\0";
    error_handling(ac, av);
    cr_assert_stderr_eq_str("The combination is incorrect (try again with -h)\n");
}

Test(test_display_help, help_display, .exit_code=0)
{
    display_help();
}

Test(factorials, factorials)
{
    double fact0 = factorial(0);
    double fact1 = factorial(1);
    double fact3 = factorial(3);
    double fact5 = factorial(5);

    cr_assert_eq(fact0, 1);
    cr_assert_eq(fact1, 1);
    cr_assert_eq(fact3, 6);
    cr_assert_eq(fact5, 120);
}

Test(count_dice_full_all, count_dice)
{
    int dice[5] = {2, 3, 3, 3, 2};
    int pair = count_good_full(dice, 2);
    int three = count_good_full(dice, 3);

    cr_assert_eq(pair, 2);
    cr_assert_eq(three, 3);
}

Test(count_dice_full_notall, count_dice)
{
    int dice[5] = {2, 3, 6, 1, 1};
    int pair = count_good_full(dice, 2);
    int three = count_good_full(dice, 3);

    cr_assert_eq(pair, 1);
    cr_assert_eq(three, 1);
}

Test(count_dice_full_0, count_dice)
{
    int dice[5] = {0, 0, 0, 0, 0};
    int pair = count_good_full(dice, 2);
    int three = count_good_full(dice, 3);

    cr_assert_eq(pair, 0);
    cr_assert_eq(three, 0);
}

Test(count_dice_straight_5_good, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 1;
    dice->d[1] = 2;
    dice->d[2] = 3;
    dice->d[3] = 4;
    dice->d[4] = 5;
    dice->nbr[0] = 5;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 5);
    free(dice);
}

Test(count_dice_straight_5_3, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 1;
    dice->d[1] = 2;
    dice->d[2] = 3;
    dice->d[3] = 3;
    dice->d[4] = 3;
    dice->nbr[0] = 5;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 3);
    free(dice);
}

Test(count_dice_straight_5_0, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 0;
    dice->d[1] = 0;
    dice->d[2] = 0;
    dice->d[3] = 0;
    dice->d[4] = 0;
    dice->nbr[0] = 5;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 0);
    free(dice);
}

Test(count_dice_straight_6_good, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 6;
    dice->d[1] = 2;
    dice->d[2] = 3;
    dice->d[3] = 4;
    dice->d[4] = 5;
    dice->nbr[0] = 6;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 5);
    free(dice);
}

Test(count_dice_straight_6_3, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 6;
    dice->d[1] = 2;
    dice->d[2] = 3;
    dice->d[3] = 1;
    dice->d[4] = 1;
    dice->nbr[0] = 6;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 3);
    free(dice);
}

Test(count_dice_straight_6_0, count_dice)
{
    dice_t *dice = malloc(sizeof(dice_t));
    int good = 0;

    dice->d[0] = 0;
    dice->d[1] = 0;
    dice->d[2] = 0;
    dice->d[3] = 0;
    dice->d[4] = 0;
    dice->nbr[0] = 6;
    dice->nbr[1] = 0;
    dice->comb = 's';
    good = count_good_straight(dice);
    cr_assert_eq(good, 0);
    free(dice);
}

Test(check_fill_struct, fill_struc)
{
    char *av[7];
    dice_t *dice;

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "2\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "full_2_1\0";
    dice = fill_struct(av);
    cr_assert_eq(dice->d[0], 5);
    cr_assert_eq(dice->d[1], 2);
    cr_assert_eq(dice->d[2], 1);
    cr_assert_eq(dice->d[3], 1);
    cr_assert_eq(dice->d[4], 1);
    cr_assert_eq(dice->comb, 'F');
    cr_assert_eq(dice->nbr[0], 2);
    cr_assert_eq(dice->nbr[1], 1);
    free(dice);
}

Test(check_fill_struct2, fill_struc)
{
    char *av[7];
    dice_t *dice;

    av[0] = "\0";
    av[1] = "5\0";
    av[2] = "2\0";
    av[3] = "1\0";
    av[4] = "1\0";
    av[5] = "1\0";
    av[6] = "pair_2\0";
    dice = fill_struct(av);
    cr_assert_eq(dice->d[0], 5);
    cr_assert_eq(dice->d[1], 2);
    cr_assert_eq(dice->d[2], 1);
    cr_assert_eq(dice->d[3], 1);
    cr_assert_eq(dice->d[4], 1);
    cr_assert_eq(dice->comb, 'p');
    cr_assert_eq(dice->nbr[0], 2);
    cr_assert_eq(dice->nbr[1], 0);
    free(dice);
}