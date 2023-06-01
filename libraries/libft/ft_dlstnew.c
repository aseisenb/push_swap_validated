/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:42 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:50:45 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*pointer;

	pointer = (t_dlist *)malloc(sizeof(t_dlist));
	if (!(pointer))
		return_error();
	pointer->content = content;
	pointer->next = NULL;
	pointer->previous = NULL;
	return (pointer);
}
