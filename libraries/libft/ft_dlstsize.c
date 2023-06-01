/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:51:01 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:51:02 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*store;
	int		size;

	store = lst;
	size = 0;
	while (store != NULL)
	{
		size++;
		store = store->next;
	}
	return (size);
}
