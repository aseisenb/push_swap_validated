/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:12:12 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/24 15:12:16 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//пишем ошибку
void	return_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

//чистим память
void	clear(t_stack *stack, t_store *store)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	ft_lstclear(&stack->instr, &free);
	free(store->ordered_array);
}

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
