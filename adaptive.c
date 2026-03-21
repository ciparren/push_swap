/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/13 11:37:28 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

 void solve_adaptive(t_info *info)
{
    // Calculas disorder y eliges estrategia
    info->disorder = compute_disorder(info->a);
    
    if (info->disorder < 0.2f)
    {
        info->strategy = SIMPLE;
        bubblesort(info);  // O(n) (tendrías que implementar uno lineal)
    }
    else if (info->disorder < 0.5f)
    {
        info->strategy = MEDIUM;
        bubblesort(info);  // O(n√n) olve_medium
    }
    else
    {
        info->strategy = COMPLEX;
        bubblesort(info); // O(n log n) Cambiar a complex cuando esté
    }
}