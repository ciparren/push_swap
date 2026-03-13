/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/13 11:47:28 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO

/*
** PASOS PARA IMPLEMENTAR BENCHMARK.C:
**
** 1. FUNCIÓN AUXILIAR: escribir string a fd
**    - Prototipo: static void write_str(int fd, char *str)
**    - Recorrer str con un índice hasta '\0'
**    - Llamar a write(fd, str, len)
**
** 2. FUNCIÓN AUXILIAR: escribir número a fd
**    - Prototipo: static void write_number(int fd, int num)
**    - Manejar caso especial num == 0
**    - Manejar números negativos (guardar signo)
**    - Convertir dígitos a caracteres (de derecha a izquierda en buffer)
**    - Escribir resultado con write
**
** 3. FUNCIÓN AUXILIAR: escribir float con 2 decimales
**    - Prototipo: static void write_float_percent(int fd, float f)
**    - Separar parte entera y decimal (f * 100)
**    - Escribir parte entera, punto, y parte decimal (con 2 dígitos)
**    - Añadir símbolo '%' al final
**
** 4. FUNCIÓN PRINCIPAL: print_benchmark(t_info *info)
**    - Calcular total_ops sumando info->ops[0] a info->ops[10]
**    - Guardar en info->total_ops
**    - Usar las funciones auxiliares para escribir a STDERR_FILENO (2):
**
**      "[bench] disorder: X.XX%\n"
**      "[bench] strategy: <nombre>/<complejidad>\n"
**      "[bench] total_ops: X\n"
**      "[bench] sa: X sb: X ss: X pa: X pb: X\n"
**      "[bench] ra: X rb: X rr: X rra: X rrb: X rrr: X\n"
**
** 5. (Opcional) Si libft tiene ft_putstr_fd y ft_putnbr_fd, usarlos
**    en lugar de write_str y write_number para simplificar
**
** NOTA: Usar siempre fd = 2 (stderr) para el benchmark
*/