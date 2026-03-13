/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/13 11:41:51 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// atoi pero para long
long     ft_atol(const char *nptr)
{
        size_t           cont;
        int              signo;
        long       result;

        cont = 0;
        signo = 1;
        result = 0;
        while ((nptr[cont] >= 9 && nptr[cont] <= 13) || nptr[cont] == 32)
                cont++;
        if (nptr[cont] == '-' || nptr[cont] == '+')
        {
                if (nptr[cont] == '-')
                        signo = -1;
                cont++;
        }
        // al poner un número enorme, mi result puede exploding así que 
        // añadimos una comprobasiao más
        while (nptr[cont] >= '0' && nptr[cont] <= '9')
        {
                result = (result * 10) + (nptr[cont] - '0');
                if (result > 2147483648)
                    return (3000000000 * signo);
                cont++;
        }
        return (result * signo);
}

// strncmp para comprobar is_flag
int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        if (n == 0)
                return (0);
        while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
                i++;
        if (i == n)
                return (0);
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


// para ver si es válido el número (is_valid)
int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

const char *get_strategy_name(int strategy)
{
    if (strategy == SIMPLE)
        return ("Simple / O(n²)");
    else if (strategy == MEDIUM)
        return ("Medium / O(n√n)");
    else if (strategy == COMPLEX)
        return ("Complex / O(n log n)");
    else if (strategy == ADAPTIVE)
        return ("Adaptive / O(?)");
    else
        return ("Unknown");
}