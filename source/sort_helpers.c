/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:08:54 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/24 15:08:59 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//find mid index
int	find_mid_index(int bigger_index, int smallest_index)
{
	return (smallest_index + ((bigger_index - smallest_index) / 2));
}

//идем обратно от нужного элемента
void	rewind(t_dlist **stack_to_rewind)
{
	t_dlist	*stack;

	stack = *stack_to_rewind;
	while (stack->previous != NULL)
		stack = stack->previous;
	*stack_to_rewind = stack;
}

//идем до конца от нужного элемента
void	fast_forward(t_dlist **stack_to_fast_forward)
{
	t_dlist	*stack;

	stack = *stack_to_fast_forward;
	while (stack->next != NULL)
		stack = stack->next;
	*stack_to_fast_forward = stack;
}

//идем до конца и возвращаем индекс
int	last_num_index(t_dlist *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

/*  
*	если верхний элемент списка а самый маленький, скидываем его вниз
*	до тех пор пока у нас все след эл расположены по порядку, скидываем их вниз
*/
void	order_a(t_stack *stack, t_store *store)
{
	if (stack->a->index == 0)
		rotate(&stack->a, &stack->instr, 'a');
	while (((stack->a->index + 1) == (stack->a->next->index))
		&& ((stack->a->index - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	if (((stack->a->index - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	store->a.next_index_to_sort = last_num_index(stack->a) + 1;
}
