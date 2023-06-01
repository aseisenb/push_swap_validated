/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:11 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:27:12 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	partition(int *array, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	pivot = array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		j++;
	}
	temp = array[left];
	array[left] = array[i];
	array[i] = temp;
	return (i);
}

void	quick_sort(int *array, int left, int right)
{
	int	index_pivot;

	if (left < right)
	{
		index_pivot = partition(array, left, right);
		quick_sort(array, left, index_pivot - 1);
		quick_sort(array, index_pivot + 1, right);
	}
}
