/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:55:53 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/26 19:31:36 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	cc;
	char	*pointer_store;

	i = 0;
	cc = (char)c;
	pointer_store = (char *)s;
	while (i < n)
	{
		pointer_store[i] = cc;
		i++;
	}
	return ((void *)s);
}
