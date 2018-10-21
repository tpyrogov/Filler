/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:23:26 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 13:23:28 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	if (n)
	{
		str1 = s1;
		str2 = s2;
		while (n)
		{
			if (*str1 != *str2)
				return (*str1 - *str2);
			str1++;
			str2++;
			n--;
		}
	}
	return (0);
}
