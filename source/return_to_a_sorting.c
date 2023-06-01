/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:28:00 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:28:01 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	send_next_bigger_to_a(t_stack *stack, t_store *store)
{
	push(&stack->b, &stack->a, &stack->instr, 'a');
	store->b.highest_index--;
	if (stack->a->index == store->a.next_index_to_sort)
	{
		rotate(&stack->a, &stack->instr, 'a');
		store->a.next_index_to_sort++;
	}
}

static void	send_next_smaller_to_a(t_stack *stack, t_store *store)
{
	push(&stack->b, &stack->a, &stack->instr, 'a');
	rotate(&stack->a, &stack->instr, 'a');
	store->a.next_index_to_sort++;
	store->b.lowest_index++;
}

static void	define_b_values(t_stack *stack, t_store *store)
{
	t_dlist	*stack_b;

	stack_b = stack->b;
	store->b.highest_index = INT_MIN;
	store->b.lowest_index = INT_MAX;
	while (stack_b)
	{
		if (stack_b->index > store->b.highest_index)
			store->b.highest_index = stack_b->index;
		if (stack_b->index < store->b.lowest_index)
			store->b.lowest_index = stack_b->index;
		stack_b = stack_b->next;
	}
	store->b.mid_index = find_mid_index(store->b.highest_index,
			store->b.lowest_index);
}

void	sort_small_b(t_stack *stack, t_store *store)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	define_b_values(stack, store);
	if (size_b == 0)
	{
		order_a(stack, store);
		return ;
	}
	else if (size_b == 1)
		push(&stack->b, &stack->a, &stack->instr, 'a');
	else if (stack->b->index == store->a.next_index_to_sort)
		send_next_smaller_to_a(stack, store);
	else if (stack->b->index == store->b.highest_index)
		send_next_bigger_to_a(stack, store);
	else if (reverse_rotation_is_quicker(stack->b, store->a.next_index_to_sort))
		reverse_rotate(&stack->b, &stack->instr, 'b');
	else
		rotate(&stack->b, &stack->instr, 'b');
	sort_small_b(stack, store);
}

void	sort_big_b(t_stack *stack, t_store *store)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	define_b_values(stack, store);
	if (size_b == 0)
		return ;
	if ((stack->b->index > store->b.mid_index) || (size_b == 1))
		push(&stack->b, &stack->a, &stack->instr, 'a');
	else if (stack->b->index == store->a.next_index_to_sort)
		send_next_smaller_to_a(stack, store);
	else if (reverse_rotation_is_quicker(stack->b, store->a.next_index_to_sort))
		reverse_rotate(&stack->b, &stack->instr, 'b');
	else
		rotate(&stack->b, &stack->instr, 'b');
	sort_big_b(stack, store);
}
