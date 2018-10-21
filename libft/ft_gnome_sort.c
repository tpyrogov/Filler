/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnome_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:04:31 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/30 20:04:33 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_gnome_sort(int *arr, size_t size)
{
	size_t i;
	size_t j;

	i = 1;
	j = 2;
	while (i < size)
	{
		if (arr[i - 1] <= arr[i])
		{
			i = j;
			j++;
		}
		else
		{
			ft_swap(&arr[i - 1], &arr[i]);
			i -= 1;
			if (i == 0)
				i = 1;
		}
	}
}
