/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:37:28 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 16:37:29 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa(int n)
{
	char	*s;
	long	num;
	int		size;
	int		i;

	i = 0;
	num = (long)n;
	size = ft_count_digits(n);
	if (num < 0)
		size++;
	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (num < 0)
	{
		s[i++] = '-';
		num *= -1;
	}
	while (i < size)
	{
		s[i] = num / ft_pow(10, size - i - 1) + '0';
		num %= ft_pow(10, size - i - 1);
		i++;
	}
	s[i] = '\0';
	return (s);
}
