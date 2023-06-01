/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:49:53 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:49:54 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(int))
{
	t_dlist	*store;

	if (lst == NULL)
		return ;
	store = lst;
	while (store != NULL)
	{
		f(store->content);
		ft_putchar('\n');
		store = store->next;
	}
}

void	ft_dlstiter_reverse(t_dlist *lst, void (*f)(int))
{
	t_dlist	*store;

	if (lst == NULL)
		return ;
	store = lst;
	while (store->next != NULL)
		store = store->next;
	while (store != NULL)
	{
		f(store->content);
		ft_putchar('\n');
		store = store->previous;
	}
}
