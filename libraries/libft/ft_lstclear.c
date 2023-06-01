/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:42:41 by aseisenb          #+#    #+#             */
/*   Updated: 2022/06/01 17:02:10 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store;
	t_list	*temp;

	store = *lst;
	if (store == NULL)
		return ;
	while (store != NULL)
	{
		temp = store->next;
		del(store);
		store = temp;
	}
	*lst = NULL;
}
