/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:35:23 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/27 14:28:08 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;

	memory = malloc(nmemb * size);
	if (!memory)
		return (0);
	ft_bzero((void *)memory, (nmemb * size));
	return ((void *)memory);
}
