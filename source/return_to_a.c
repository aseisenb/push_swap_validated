/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:28:17 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:28:18 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Push from stack a to stack b if index is less than max index
*	and if index is is more than next one to be sorted.
*/
static void	resend_to_b(t_stack *stack, t_store *store, int limit)
{
	while ((stack->a->index <= limit)
		&& (stack->a->index >= store->a.next_index_to_sort))
		push(&stack->a, &stack->b, &stack->instr, 'b');
}

/*
*	Push back nodes from stack b to stack a.
*	Algo is diff for less than 50 and more than 50.
*/
void	return_half_to_a(t_stack *stack, t_store *store, int limit)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	if (size_b < 50)
	{
		sort_small_b(stack, store);
		return ;
	}
	sort_big_b(stack, store);
	resend_to_b(stack, store, limit);
	return_half_to_a(stack, store, limit);
}
