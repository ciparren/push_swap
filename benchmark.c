/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 10:18:06 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libc/libft.h"

void print_bench(t_info *info)
{
    bench_disorder(info);
    bench_strategy(info);
    bench_total_ops(info);
    bench_ops(info);
}

void bench_disorder(t_info *info)
{
    ft_putstr_fd("[bench] disorder: ",2);
    ft_putfloat_fd(info->disorder*100, 2, 2);
    ft_putstr_fd("%\n", 2);
}
void bench_strategy(t_info *info)
{
    if (info->strategy == 0)
    {
        ft_putstr_fd("[bench] strategy: Adaptative / ", 2);
        if (info->disorder < 0.2f)
            ft_putstr_fd("O(n²)\n", 2);
        else if (info->disorder < 0.5f)
            ft_putstr_fd("O(n√n)\n", 2);
        else
            ft_putstr_fd("O(n√n)\n", 2);
    }
    else if (info->strategy == 1)
    {
        ft_putstr_fd("[bench] strategy: Simple / O(n²)\n", 2);
    }
    else if (info->strategy == 2)
    {
        ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n", 2);
    }
    else if (info->strategy == 3)
    {
        ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
    }
}
void bench_total_ops(t_info *info)
{
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(total_ops(info), 2);
    ft_putstr_fd("\n", 2);
}
void bench_ops(t_info *info)
{
    ft_putstr_fd("[bench] sa: ", 2);
    ft_putnbr_fd(info->ops[5], 2);
    ft_putstr_fd(" sb: ", 2);
    ft_putnbr_fd(info->ops[6], 2);
    ft_putstr_fd(" ss: ", 2);
    ft_putnbr_fd(info->ops[7], 2);
    ft_putstr_fd(" pa: ", 2);
    ft_putnbr_fd(info->ops[0], 2);
    ft_putstr_fd(" pb: ", 2);
    ft_putnbr_fd(info->ops[1], 2);
    ft_putstr_fd("\n[bench] ra: ", 2);
    ft_putnbr_fd(info->ops[2], 2);
    ft_putstr_fd(" rb: ", 2);
    ft_putnbr_fd(info->ops[3], 2);
    ft_putstr_fd(" rr: ", 2);
    ft_putnbr_fd(info->ops[4], 2);
    ft_putstr_fd(" rra: ", 2);
    ft_putnbr_fd(info->ops[8], 2);
    ft_putstr_fd(" rrb: ", 2);
    ft_putnbr_fd(info->ops[9], 2);
    ft_putstr_fd(" rrr: ", 2);
    ft_putnbr_fd(info->ops[10], 2);
    ft_putstr_fd("\n", 2);
}
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