/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:09:08 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/24 15:09:11 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Check if stack a is sorted.
*	Return 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_dlist *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content > stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

/*
*	Check if stack a is full.
*	Return 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_full(t_dlist *stack, int total_numbers)
{
	int	numbers_in_stack;

	numbers_in_stack = 0;
	while (stack->next != NULL)
	{
		numbers_in_stack++;
		stack = stack->next;
	}
	numbers_in_stack++;
	if (numbers_in_stack == total_numbers)
		return (1);
	return (0);
}

int	is_duplicate(t_dlist *lst, int number)
{
	t_dlist	*store;

	if (lst == NULL)
		return (0);
	store = lst;
	while (store != NULL)
	{
		if ((int)store->content == number)
			return (1);
		store = store->next;
	}
	return (0);
}

int	find_true_index(t_stack *stack, t_store *store, int index)
{
	if (store->ordered_array[index] == stack->a->content)
		return (index);
	return (find_true_index(stack, store, (index + 1)));
}

/*
*	если следующий индекс пустой, то есть мы должны дойти до конца списка
*	присваем индекс, отмотали пленку назад, вернулись к началу
*	присваеваем индекс, идем на след индекс, повторяем все с начала
*/
void	assign_indixes_to_stack(t_stack *stack, t_store *store)
{
	if (stack->a->next == NULL)
	{
		stack->a->index = find_true_index(stack, store, 0);
		rewind(&stack->a);
		return ;
	}
	stack->a->index = find_true_index(stack, store, 0);
	stack->a = stack->a->next;
	assign_indixes_to_stack(stack, store);
}
