/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:49:19 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:49:22 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*store;
	t_dlist	*temp;

	store = *lst;
	if (store == NULL)
		return ;
	while (store != NULL)
	{
		temp = store->next;
		free(store);
		store = temp;
	}
	*lst = NULL;
}
