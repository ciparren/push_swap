/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:00:00 by ciparren          #+#    #+#             */
/*   Updated: 2026/03/18 10:19:30 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inicializar info
void	init_info(t_info *info)
{
	info->a = malloc(sizeof(t_stack));
	info->b = malloc(sizeof(t_stack));
	
	if (!info->a || !info->b)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	
	info->a->top = NULL;
	info->a->size = 0;
	info->b->top = NULL;
	info->b->size = 0;
	
	for (int i = 0; i < 11; i++)
		info->ops[i] = 0;
	
	info->total_ops = 0;
	info->bench = 0;
	info->strategy = SIMPLE;
	info->disorder = 0.0f;
}

// Liberar memoria
void	free_all(t_info *info)
{
	if (info->a)
	{
		free_stack(info->a);
		free(info->a);
	}
	if (info->b)
	{
		free_stack(info->b);
		free(info->b);
	}
}

// Generar números aleatorios sin repetir
void	generate_random_numbers(t_info *info, int count)
{
	int		*nums;
	int		i;
	int		j;
	int		unique;
	
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return ;
	
	// Inicializar semilla
	srand(time(NULL));
	
	// Generar números únicos
	i = 0;
	while (i < count)
	{
		nums[i] = rand() % 1000; // Números entre 0 y 999
		unique = 1;
		j = 0;
		while (j < i)
		{
			if (nums[j] == nums[i])
			{
				unique = 0;
				break ;
			}
			j++;
		}
		if (unique)
		{
			append_node(info, nums[i]);
			i++;
		}
	}
	free(nums);
}

// Cargar números específicos para pruebas
void	load_test_numbers(t_info *info, int *nums, int size)
{
	for (int i = 0; i < size; i++)
		append_node(info, nums[i]);
}

// Probar benchmark con diferentes configuraciones
void	test_benchmark(int strategy, int bench_flag, int *nums, int size, char *desc)
{
	t_info	info;
	
	printf("\n════════════════════════════════════════════\n");
	printf("TEST: %s\n", desc);
	printf("Estrategia: %s | Benchmark: %s\n", 
		   strategy == SIMPLE ? "SIMPLE" : 
		   strategy == MEDIUM ? "MEDIUM" : 
		   strategy == COMPLEX ? "COMPLEX" : "ADAPTIVE",
		   bench_flag ? "ON" : "OFF");
	printf("════════════════════════════════════════════\n");
	
	init_info(&info);
	info.strategy = strategy;
	info.bench = bench_flag;
	
	// Cargar números
	load_test_numbers(&info, nums, size);
	
	// Calcular disorder ANTES de ordenar
	info.disorder = compute_disorder(info.a);
	printf("Disorder calculado: %.2f%%\n\n", info.disorder * 100);
	
	// Ejecutar algoritmo según estrategia
	printf("--- INICIO DE OPERACIONES (stdout) ---\n");
	if (strategy == SIMPLE)
		bubblesort(&info);  // Usamos bubblesort como placeholder
	else if (strategy == MEDIUM)
		solve_medium(&info);
	else if (strategy == COMPLEX)
		printf("(COMPLEX aún no implementado)\n");
	else if (strategy == ADAPTIVE)
		printf("(ADAPTIVE aún no implementado)\n");
	printf("--- FIN DE OPERACIONES (stdout) ---\n\n");
	
	// Mostrar resumen de operaciones
	printf("--- ESTADO FINAL ---\n");
	printf("Stack A size: %d\n", info.a->size);
	printf("Stack B size: %d\n", info.b->size);
	printf("Total ops: %d\n", total_ops(&info));
	
	// Si benchmark está activo, se imprimirá a stderr
	if (info.bench)
	{
		printf("\n--- SALIDA BENCHMARK (stderr) ---\n");
		print_bench(&info);
		printf("--- FIN BENCHMARK ---\n");
	}
	
	free_all(&info);
}

// Probar con diferentes tamaños
void	test_sizes(void)
{
	int	small[] = {3, 1, 4, 2, 5};
	int	medium[] = {9, 3, 7, 1, 8, 2, 6, 4, 5, 10};
	int	large[20];
	
	// Generar array grande
	for (int i = 0; i < 20; i++)
		large[i] = i + 1;
	// Desordenar un poco
	large[0] = 20;
	large[19] = 1;
	
	printf("\n========================================\n");
	printf("   PRUEBAS DE BENCHMARK - push_swap\n");
	printf("========================================\n");
	
	// Test 1: Simple sin benchmark
	test_benchmark(SIMPLE, 0, small, 5, "Simple - 5 nums - SIN benchmark");
	
	// Test 2: Simple con benchmark
	test_benchmark(SIMPLE, 1, small, 5, "Simple - 5 nums - CON benchmark");
	
	// Test 3: Medium con benchmark
	test_benchmark(MEDIUM, 1, medium, 10, "Medium - 10 nums - CON benchmark");
	
	// Test 4: Adaptive (placeholder) con benchmark
	test_benchmark(ADAPTIVE, 1, medium, 10, "Adaptive - 10 nums - CON benchmark");
	
	// Test 5: Complex (placeholder) con benchmark
	test_benchmark(COMPLEX, 1, large, 20, "Complex - 20 nums - CON benchmark");
}

int	main(void)
{
	// Ejecutar todas las pruebas
	test_sizes();
	
	// Prueba adicional: redirección de stderr a archivo
	printf("\n========================================\n");
	printf("   PRUEBA DE REDIRECCIÓN\n");
	printf("========================================\n");
	printf("Ejecuta: ./push_swap_bench 2> bench_output.txt\n");
	printf("Esto guardará el benchmark en bench_output.txt\n");
	printf("Mientras las operaciones (stdout) se ven en pantalla\n");
	
	return (0);
}