/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:08:41 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/24 15:08:46 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  
*	Define the position of numbers.
*/
static void	define_numbers(int *first, int *second, int *last, t_dlist *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

/*  
*	Manually doing the sort.
*/

static void	sort_three(t_stack *stack, int *first, int *second, int *last)
{
	if (is_sorted(stack->a))
		return ;
	if ((*first > *second && *last > *second && *first < *last)
		|| (*first > *second && *last < *second && *first > *last)
		|| (*first < *second && *last < *second && *first < *last))
		swap(&stack->a, &stack->instr, 'a');
	define_numbers(first, second, last, stack->a);
	if (*first > *second && *last > *second && *first > *last)
		rotate(&stack->a, &stack->instr, 'a');
	if (*first < *second && *last < *second && *first > *last)
		reverse_rotate(&stack->a, &stack->instr, 'a');
}

/*  
*	In stack b, if node is less then next node, we swap.
*	Than push to stack a.
*	In stack a. If node is more than next node, we swap.
*/
static void	return_to_a(t_stack *stack)
{
	if (!stack->b)
		return ;
	if (stack->b->next)
		if (stack->b->index < stack->b->next->index)
			swap(&stack->b, &stack->instr, 'b');
	push(&stack->b, &stack->a, &stack->instr, 'a');
	if (stack->a->index > stack->a->next->index)
		swap(&stack->a, &stack->instr, 'a');
	return_to_a(stack);
}

/*  
*	Stack a. If index is 0 or 1 push to stack b.
*	Else rotate in stack a.
*/
static void	send_to_b(t_stack *stack, t_store *store, int total_numbers)
{
	if (ft_dlstsize(stack->a) == 3)
		return ;
	if ((stack->a->index == 0) || (stack->a->index == 1))
	{
		store->a.highest_index--;
		push(&stack->a, &stack->b, &stack->instr, 'b');
	}
	else
		rotate(&stack->a, &stack->instr, 'a');
	send_to_b(stack, store, total_numbers);
}

/*  
*	Algo for small sort. If size is 2 swap.
*	If size is 3 define numbers and go to sort_three.
*	If size is 4 or 5 go to send_to_be.
*/
void	small_sort(t_stack *stack, t_store *store, int total_numbers)
{
	int	first;
	int	second;
	int	last;

	(void)store;
	if (is_sorted(stack->a) && is_full(stack->a, total_numbers))
		return ;
	if (ft_dlstsize(stack->a) == 2)
	{
		swap(&stack->a, &stack->instr, 'a');
		return ;
	}
	if (ft_dlstsize(stack->a) == 3)
	{
		define_numbers(&first, &second, &last, stack->a);
		sort_three(stack, &first, &second, &last);
		return_to_a(stack);
	}
	else
		send_to_b(stack, store, total_numbers);
	small_sort(stack, store, total_numbers);
}
