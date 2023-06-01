/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:18:16 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/27 15:16:40 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[i] == '\0')
		return (b);
	if (b[i] == '\0' || len == 0)
		return (0);
	while (i < len && b[i] != 0)
	{
		j = 0;
		while ((i + j) < len && b[i + j] && b[i + j] == l[j])
		{
			j++;
			if (l[j] == '\0')
				return (b + i);
		}
		i++;
	}
	return (NULL);
}
