/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:55:51 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/30 19:55:53 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_sort(int *arr, size_t size, int assc)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (assc == 1)
			{
				if (arr[j] >= arr[j + 1])
					ft_swap(&arr[j], &arr[j + 1]);
			}
			else
			{
				if (arr[j] <= arr[j + 1])
					ft_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}
