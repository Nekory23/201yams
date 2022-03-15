/*
** EPITECH PROJECT, 2021
** 201yams
** File description:
** compute the probabilities
*/

#include <stdio.h>
#include "yams.h"

double factorial(double nbr)
{
    double res = 1;

    if (nbr == 0)
        return 1;
    for (int i = nbr; i !=0; i--)
        res *= i;
    return res;
}

double combination(double k, double n)
{
    double fn = factorial(n);
    double fk = factorial(k);
    double fnk = factorial(n - k);

    return (fn / (fk * fnk));
}

double binomial(double k, double n)
{
    double comb = combination(k,n);
    double p = pow((double)1/6, k);
    double pc = pow((double)5/6, n - k);

    return (comb * p * pc);
}