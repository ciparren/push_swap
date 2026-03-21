/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:14:06 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 09:52:08 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 // TODO parsear si viene una parte de la pila entre comillas, ejemplo: "2 13 4 56 1" 4 3 2
 //TODO PARSEAR SI LA PILA B ESTÁ VACÍA.
// TODO
// En parser.c, falta:
// 1. Manejar argumentos entre comillas: "1 2 3 4"
// 2. Verificar que info->a y info->b están inicializados antes de usarlos
// 3. En error_exit, estás llamando a free_stack con punteros no inicializados 


void parse_args(int argc, char **argv, t_info *info)
{
    int i;

    i = 1;
    while(i < argc)
    {
        if(is_flag(argv[i], info))
        {
            // tenemos que actualizar el atributo de info -> flag bench
        }
        if(is_valid_number(argv[i]))
        {
            // lo metemos en la pila
            process_number(argv[i], info);
        }
        else
        {
            // error
            write(2, "Error\n", 6);
            // liberamos toda la memoria asignada
        }
        i++;
    }
}

int is_flag(char *arg, t_info *info)
{
    // Aquí usarás tu ft_strncmp o similar.
    // Si es "--bench", info->flag_bench = 1; return 1;
    // Si es "--simple", info->strategy = SIMPLE; return 1;
    // Si no es ninguna flag, return 0;
    if(ft_strncmp(arg, "--bench", 8) == 0)
        info->bench = 1;
    else if(ft_strncmp(arg, "--adaptive", 11) == 0)
        info->strategy = ADAPTIVE;
    else if(ft_strncmp(arg, "--simple", 9) == 0)
        info->strategy = SIMPLE;
    else if(ft_strncmp(arg, "--medium", 9) == 0)
        info->strategy = MEDIUM;
    else if(ft_strncmp(arg, "--complex", 10) == 0)
            info->strategy = COMPLEX;
    else    
        return 0;
    return 1;
}


int is_valid_number(char *arg)
{
    // Bucle para ver si str[i] es '-' o '+' solo en i == 0
    // Y que el resto sean dígitos ('0' a '9')
    // Si hay letras o está vacío, return 0;
    // Si todo va bien, return 1;
    int i;

    i = 0;
    if(arg[i] == '-' || arg[i] == '+')
        i++;
    if(arg[i] == '\0')
        return (0);
    while ((arg[i]))
    {
        if(!ft_isdigit(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

void process_number(char *str, t_info *info)
{
    // convertir en int
    // añadir a la pila A
    long    num;

    num = ft_atol(str);
    if (num > 2147483647 || num < -2147483648)
        error_exit(info);
    // vamos a ver si hay duplicados.
    if(check_dup(info->a, (int)num))
        error_exit(info);
    append_node(info, (int) num);
}

void error_exit(t_info *info)
{
    write(2, "Error\n", 6);
    if(info)
    {
        if(info->a)
            free_stack(info->a);
        if(info->b)
            free_stack(info->b);
    }
    exit(1);
}

void free_stack(t_stack *stack)
{
    t_node *curr;
    t_node *next_node;

    if(!stack)
        return ;
    curr = stack->top->next;
    while (curr != stack->top)
    {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    free(stack->top);
    free(stack);
}

int check_dup(t_stack *a, int num)
{
    t_node *curr;
    
    curr = a->top;
    while(curr != a->top)
    {
        if(curr->value == num)
            return 1;
        curr = curr->next;
    }
    return 0;
}

void append_node(t_info *info, int num)
{
    t_node *to_append;
    t_node *last;
   
    to_append = malloc(sizeof(t_node));
    if(!to_append)
        error_exit(info);
    to_append->value = num;
    if(info->a->top->next == NULL)
    {
        info->a->top->next = to_append;
        to_append->next = info->a->top;
        to_append->prev = info->a->top;
    }
    else
    {
        last = info->a->top->prev;

        to_append->next = info->a->top;
        to_append->prev = last;

        last->next = to_append;
        info->a->top->prev = to_append;
    }
    info->a->size++;
}

void insert_index(t_info *info)
{
    t_node *current;
    t_node *cmp;
    int idx;
    int i;
    int j;

    if(!info->a || info->a->size == 0)
        return ;
    current = info->a->top->next;
    i = 0;
    while (i < info->a->size)
    {
        idx = 0;
        cmp = info->a->top->next;
        j = 0;
        while (j < info->a->size)
        {
            if (cmp->value < current->value)
                idx++;
            cmp = cmp->next;
            j++;
        }
        current->index = idx;
        current = current->next;
        i++;
    }
}

