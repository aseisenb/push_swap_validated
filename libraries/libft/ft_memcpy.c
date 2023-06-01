/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:33:00 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/27 14:13:37 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest_t;
	const unsigned char	*src_t;

	if (!dest && !src)
		return (dest);
	i = 0;
	dest_t = (unsigned char *)dest;
	src_t = (const unsigned char *)src;
	while (i < len)
	{
		dest_t[i] = src_t[i];
		i++;
	}
	return (dest);
}
