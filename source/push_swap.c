/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:01 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:27:02 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fill_and_sort_array(t_dlist *stack_a, int total)
{
	int	*ordered_array;
	int	i;

	ordered_array = (int *)malloc((total) * sizeof(int));
	if (!ordered_array)
		return_error();
	i = 0;
	while (i < (total))
	{
		ordered_array[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	quick_sort(ordered_array, 0, (total - 1));
	return (ordered_array);
}

/*
*	Checks if a stack is sorted and full and exit.
*	If stack a is less than 5 do a small sort.
*	If not send half of stack a to b.
*	When finish return all back to a. Start again.
*/
void	sort(t_stack *stack, t_store *store)
{
	if (is_sorted(stack->a) && is_full(stack->a, store->total_num))
		return ;
	if (ft_dlstsize(stack->a) <= 5)
		small_sort(stack, store, ft_dlstsize(stack->a));
	else
	{
		send_half_to_b(stack, store);
		return_half_to_a(stack, store, store->b.highest_index);
	}
	sort(stack, store);
}

/*  
*	Initialize stack a, b and instuctions (to write the order)
*/
static void	init_stacks(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->instr = NULL;
}

/*  
*	Checks if the argument is correct, initialize stacks,
*	fill stack a and prepare auxiliary data structure and sorts the stacks. 
*	When sorting is done, reduce operations, print operations
*	and free the stacks and exit.
*/
int	main(int argc, char **argv)
{
	t_stack	stack;
	t_store	store;

	if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = check_string(&argc, argv);
	check_args(argc, argv);
	init_stacks(&stack);
	initialize(&stack, &store, argc, argv);
	sort(&stack, &store);
	reduce_operations(&stack.instr);
	ft_lstiter(stack.instr, &ft_putstr);
	clear(&stack, &store);
	return (0);
}
