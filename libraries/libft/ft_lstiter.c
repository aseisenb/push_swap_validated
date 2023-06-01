/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:02:44 by aseisenb          #+#    #+#             */
/*   Updated: 2022/06/01 17:14:47 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(const char *))
{
	t_list	*store;

	if (lst == NULL)
		return ;
	store = lst;
	while (store != NULL)
	{
		f(store->content);
		store = store->next;
	}
}
