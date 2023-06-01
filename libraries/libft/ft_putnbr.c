/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:47:05 by aseisenb          #+#    #+#             */
/*   Updated: 2022/05/27 13:40:33 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		number = nb * -1;
		ft_putchar('-');
	}
	else
	{
		number = nb;
	}
	if (number / 10 < 1)
	{
		ft_putchar(number + '0');
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}
