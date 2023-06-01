/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:10 by aseisenb          #+#    #+#             */
/*   Updated: 2022/06/01 14:43:39 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pointer;

	pointer = (t_list *)malloc(sizeof(t_list));
	if (!pointer)
		return (NULL);
	pointer->content = content;
	pointer->next = NULL;
	return (pointer);
}
