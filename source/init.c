/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:26:34 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:26:35 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  
*	Intializing stack a. Transforming char to int.
*	Creating first node and putting there first number.
*	Repeating sequence until the end of arguments.
*	If duplicates return error. If not adding node to the end.
*/
void	init_stack_a(int argc, char **argv, t_dlist	**stack_a)
{
	int	number;
	int	i;

	i = 0;
	number = (int)ft_atoi(argv[i]);
	*stack_a = ft_dlstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		if (is_duplicate(*stack_a, number))
			return_error();
		else
			ft_dlstadd_back(stack_a, ft_dlstnew(number));
	}
}

/*  
*	Intialize auxiliary data structure to store data about operations.
*	Allocating memory. Initiliazing total amount of numbers.
*	Iinitializing ordered array, last index to track amount of numbers 
*	in stack a&b to count chunks. Initializing the number next one in 
*	order to be sorted and a.mid index
*/
static void	init_store(t_dlist *stack_a, t_store *store, int argc)
{
	ft_memset(store, 0, sizeof(*store));
	store->total_num = argc;
	store->ordered_array = fill_and_sort_array(stack_a, store->total_num);
	store->a.highest_index = store->total_num - 1;
	store->a.next_index_to_sort = 0;
	store->a.mid_index = find_mid_index(store->a.highest_index,
			store->a.next_index_to_sort);
}

/*  
*	Initialize stack a and fill it with arguments,
*	Intialize auxiliary data structure. 
*	Assign each number on the stack to its index in the sorted array.
*/
void	initialize(t_stack *stack, t_store *store, int argc, char **argv)
{
	init_stack_a(argc, argv, &stack->a);
	init_store(stack->a, store, argc);
	assign_indixes_to_stack(stack, store);
}
