/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:28:32 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:28:33 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Checking if there is a node with index less than middle
*/
int	any_small_in_stack_a(t_dlist *stack_a, t_store *store)
{
	while (stack_a != NULL)
	{
		if (stack_a->index <= store->a.mid_index)
			if (stack_a->index >= store->a.next_index_to_sort)
				return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/*
*	Updating data in auxilary.
*/
static void	init_values(t_stack *stack, t_store *store, int *size_a)
{
	*size_a = ft_dlstsize(stack->a);
	store->b.highest_index = INT_MIN;
	store->b.lowest_index = INT_MAX;
	store->a.mid_index = find_mid_index(store->a.highest_index,
			store->a.next_index_to_sort);
}

/*
*	Push from stack a to stack b.
*	Overwrite highest and lowest index.
*/
static void	send_to_b(t_stack *stack, t_store *store)
{
	push(&stack->a, &stack->b, &stack->instr, 'b');
	if (stack->b->index > store->b.highest_index)
		store->b.highest_index = stack->b->index;
	if (stack->b->index < store->b.lowest_index)
		store->b.lowest_index = stack->b->index;
}

/*
*	1. If in stack a there is a node less than medium index push to stack b.
*	If there is a node higher than med. index send down
*	2. If in stack a there is a number next one in order to be sorted
*	send back all nodes that we sent down.
*/
static void	send_smallers_to_b(t_stack *stack, t_store *store, int size_a)
{
	int		rotations;
	int		i;

	i = 0;
	rotations = 0;
	while ((i < size_a) && (any_small_in_stack_a(stack->a, store)))
	{
		if (stack->a->index <= store->a.mid_index)
			send_to_b(stack, store);
		else
		{
			rotate(&stack->a, &stack->instr, 'a');
			rotations++;
		}
		i++;
	}
	if (store->a.next_index_to_sort)
	{
		i = 0;
		while (i < rotations)
		{
			reverse_rotate(&stack->a, &stack->instr, 'a');
			i++;
		}
	}
}

/*
*	Initialize values.
*	1. If a.higher index minus a.next index to sort is less than 10
*	and while index is more than 0 send arguments to stack b.
*	2. If not send small indexes to b.
*/
void	send_half_to_b(t_stack *stack, t_store *store)
{
	int		size_a;

	init_values(stack, store, &size_a);
	if ((store->a.highest_index - store->a.next_index_to_sort) < LAST_CHUNCK)
		while (stack->a->index > 0)
			send_to_b(stack, store);
	else
		send_smallers_to_b(stack, store, size_a);
}
