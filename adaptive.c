/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/07 11:08:43 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"   // TODO

 void solve_adaptive(t_info *info)
{
    // Calculas disorder y eliges estrategia
    info->disorder = compute_disorder(*info->a);
    
    if (info->disorder < 0.2)
        solve_simple(info);  // O(n) (tendrías que implementar uno lineal)
    else if (info->disorder < 0.5)
        solve_medium(info);  // O(n√n)
    else
        solve_complex(info); // O(n log n)
}