/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:30:31 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/26 18:20:20 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = 0;
	i = 0;
	c = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == c)
			last = (char *)(s + i);
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (last);
}
